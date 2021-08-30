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

static t_philo	*philo_new(t_opt opts, int i, int *vital, long start_t)
{
	t_philo	*elem;

	elem = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!elem)
		return (NULL);
	elem->vital = vital;
	elem->nth = i;
	elem->n_eat = 0;
	elem->cur_act = 's';
	elem->opts = opts;
	elem->prev_t = start_t;
	pthread_mutex_init(&(elem->fork), NULL);
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

static long	time_cal(long prev_t)
{
	struct timeval		c_time;
	long	cur_t;
	long	ret;

	gettimeofday(&c_time, NULL);
	cur_t = (long)c_time.tv_usec + (long)c_time.tv_sec * 1000000;
	ret = (cur_t - prev_t) / 1000;
	return (ret);
}

static long	get_now(struct timeval *cur)
{
	long	ret;

	gettimeofday(cur, NULL);
	ret = (long)cur->tv_sec * 1000000 + (long)cur->tv_usec;
	return (ret);
}

static void	ft_usleep(long interval)
{
	struct timeval	cur;
	long	end;
	long	now;

	get_now(&cur);
	now = (long)cur.tv_sec * 1000000 + (long)cur.tv_usec;
	end = interval + now;
	while (end > get_now(&cur))
		usleep(100);
}

static void	*philo_action(void *arg)
{
	t_philo *philo;
	int	i;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&(philo->fork));
		pthread_mutex_lock(&(philo->next->fork));
		printf("%ldms %d has taken a fork\n", time_cal(philo->prev_t), philo->nth);
		printf("%ldms %d has taken a fork\n", time_cal(philo->prev_t), philo->nth);
		printf("%ldms %d is eating\n", time_cal(philo->prev_t), philo->nth);
		ft_usleep(philo->opts.time_eat * 1000);
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->fork));
		printf("%ldms %d is sleeping\n", time_cal(philo->prev_t), philo->nth);
		ft_usleep(philo->opts.time_slp * 1000);
		printf("%ldms %d is thinking\n", time_cal(philo->prev_t), philo->nth);
	}
	return (NULL);
}

/* TODO ==============================
- time accuracy has been immensely improved, but cannot find a certain answer to kernel panic...why does usleep prevent kernel panic?
- death check system
====================================*/

int	main(int argc, char *argv[])
{
	t_opt			opts;
	t_philo			*head;
	t_philo 		*cur;
	int				i;
	int				vital;
	struct timeval	time;
	long			start_t;

	if (!check_fill_opts(argc, argv, &opts))
		return (1);
	head = philo_new(opts, -1, NULL, 0);
	if (!head)
		return (1);
	gettimeofday(&time, NULL);
	start_t = (long)time.tv_usec + (long)time.tv_sec * 1000000;
	vital = 0;
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(&head, philo_new(opts, i, &vital, start_t)))
			return (1);
	}
	cur = head->next;
	i = -1;
	while (++i < opts.n_philo)
	{
		pthread_create(&(cur->tid), NULL, philo_action, cur);
		cur = cur->next;
	}
	i = -1;
	while (++i < opts.n_philo)
	{
		pthread_join(cur->tid, NULL);
		cur = cur->next;
	}
	free_alloc(head, opts.n_philo);
	return (0);
}
