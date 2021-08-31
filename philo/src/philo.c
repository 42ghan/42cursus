/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:18:59 by ghan              #+#    #+#             */
/*   Updated: 2021/08/23 12:18:59 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check_fill_opts(int ac, char **av, t_opt *opts)
{
	if (!(ac == 5 || ac == 6))
		return (0);
	opts->n_philo = ft_atoi(av[1]);
	opts->time_die = ft_atoi(av[2]);
	opts->time_eat = ft_atoi(av[3]);
	opts->time_slp = ft_atoi(av[4]);
	if (opts->n_philo < 1 || opts->time_die < 0
		|| opts->time_eat < 0 || opts->time_slp < 0)
		return (0);
	opts->n_must_eat = -1;
	if (ac == 6)
	{
		opts->n_must_eat = ft_atoi(av[5]);
		if (opts->n_must_eat < 0)
			return(0);
	}
	return (1);
}

static t_philo	*philo_new(t_opt opts, int i, long start_t, int *vital, pthread_mutex_t *vital_m)
{
	t_philo	*elem;

	elem = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!elem)
		return (NULL);
	elem->nth = i;
	elem->n_eat = 0;
	elem->opts = opts;
	elem->start_t = start_t;
	elem->last_eat_t = elem->start_t;
	pthread_mutex_init(&(elem->fork), NULL);
	elem->vital_m = vital_m;
	elem->vital = vital;
	if (i == -1)
		elem->next = NULL;
	return (elem);
}

static int	philo_addback(t_philo **head, t_philo *new)
{
	t_philo	*cur;

	if (!new)
		return (0);
	if (!(*head)->next)
	{
		(*head)->next = new;
		new->next = new;
	}
	cur = (*head)->next;
	while (cur->next != (*head)->next)
		cur = cur->next;
	cur->next = new;
	new->next = (*head)->next;
	return (1);
}

static long	time_cal(long start_t)
{
	struct timeval	c_time;
	long			cur_t;
	long			ret;

	gettimeofday(&c_time, NULL);
	cur_t = (long)c_time.tv_sec * 1000000 + (long)c_time.tv_usec;
	ret = (cur_t - start_t) / 1000;
	return (ret);
}

static long	get_now(struct timeval *cur)
{
	long	ret;

	gettimeofday(cur, NULL);
	ret = (long)cur->tv_sec * 1000000 + (long)cur->tv_usec;
	return (ret);
}

static int	ft_usleep(long interval, t_philo *philo)
{
	struct timeval	cur;
	long			end;
	long			now;

	now = 	get_now(&cur);
	end = interval + now;
	while (end > get_now(&cur))
		usleep(1);
	return (1);
}

static void	*monitor_death(void *arg)
{
	struct timeval	cur;
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (*(philo->vital) == 0 && philo->last_eat_t + philo->opts.time_die * 1000 > get_now(&cur))
	{
		if (philo->opts.n_must_eat > 0 && philo->n_eat > philo->opts.n_must_eat)
			break ;
		usleep(1);
	}
	pthread_mutex_lock(philo->vital_m);
	if (*(philo->vital) == 0)
	{
		*(philo->vital) = 1;
		printf("%ldms %d died\n", time_cal(philo->start_t), philo->nth);
	}
	pthread_mutex_unlock(philo->vital_m);
	return (NULL);
}

static void	*philo_action(void *arg)
{
	struct timeval	now;
	t_philo 		*philo;
	pthread_t		monitor;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&(philo->fork));
		pthread_mutex_lock(&(philo->next->fork));
		printf("%ldms %d has taken a fork\n", time_cal(philo->start_t), philo->nth);
		printf("%ldms %d has taken a fork\n", time_cal(philo->start_t), philo->nth);
		printf("%ldms %d is eating\n", time_cal(philo->start_t), philo->nth);
		(philo->n_eat)++;
		philo->last_eat_t = get_now(&now);
		ft_usleep(philo->opts.time_eat * 1000, philo);
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->fork));
		printf("%ldms %d is sleeping\n", time_cal(philo->start_t), philo->nth);
		ft_usleep(philo->opts.time_slp * 1000, philo);
		printf("%ldms %d is thinking\n", time_cal(philo->start_t), philo->nth);
	}
	return (NULL);
}

/* TODO ==============================
- time accuracy has been immensely improved, but cannot find a certain answer to kernel panic...why does usleep prevent kernel panic?
- improve death system
- finishing the program after must_eat_rep has been reached
====================================*/

int	main(int argc, char *argv[])
{
	t_opt			opts;
	t_philo			*head;
	t_philo 		*cur;
	int				i;
	struct timeval	time;
	int				vital;
	long			start_t;
	pthread_mutex_t vital_m;

	if (!check_fill_opts(argc, argv, &opts))
		return (1);
	head = philo_new(opts, -1, 0, NULL, NULL);
	if (!head)
		return (1);
	gettimeofday(&time, NULL);
	start_t = (long)time.tv_sec * 1000000 + (long)time.tv_usec;
	pthread_mutex_init(&vital_m, NULL);
	vital = 0;
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(&head, philo_new(opts, i, start_t, &vital, &vital_m)))
			return (1);
	}
	cur = head->next;
	i = -1;
	while (++i < opts.n_philo)
	{
		pthread_create(&(cur->tid), NULL, philo_action, cur);
		pthread_create(&(cur->monitor), NULL, monitor_death, cur);
		cur = cur->next;
	}
	i = -1;
	while (++i < opts.n_philo)
	{
		pthread_join(cur->monitor, NULL);
		cur = cur->next;
	}
	free_alloc(head, opts.n_philo);
	return (0);
}
