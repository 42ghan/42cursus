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

static t_philo	*philo_new(t_opt opts, int i, unsigned long long start_t)
{
	t_philo	*elem;

	elem = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!elem)
		return (NULL);
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

static unsigned long long	time_cal(unsigned long long prev_t)
{
	struct timeval		c_time;
	struct timeval		p_time;
	unsigned long long	cur_t;
	unsigned long long	ret;

	gettimeofday(&c_time, NULL);
	cur_t = (unsigned long long)c_time.tv_usec;
	cur_t += (unsigned long long)c_time.tv_sec * 1000000;
	ret = cur_t - prev_t;
	gettimeofday(&p_time, NULL);
	prev_t = (unsigned long long)p_time.tv_usec;
	prev_t += (unsigned long long)p_time.tv_sec * 1000000;
	return (ret);
}

static void	*philo_action(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	// while (1)
	// {
		pthread_mutex_lock(&(philo->fork));
		pthread_mutex_lock(&(philo->next->fork));
		printf("%llums %d has taken a fork\n", time_cal(philo->prev_t), philo->nth);
		printf("%llums %d is eating\n", time_cal(philo->prev_t), philo->nth);
		usleep(philo->opts.time_eat);
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->fork));
		printf("%llums %d is sleeping\n", time_cal(philo->prev_t), philo->nth);
		usleep(philo->opts.time_slp);
		printf("%llums %d is thinking\n", time_cal(philo->prev_t), philo->nth);
	// }
	return (NULL);
}

/* TODO ==============================
- improve time cal. function, make it more accurate
- death check system
====================================*/

int	main(int argc, char *argv[])
{
	t_opt				opts;
	t_philo				*head;
	t_philo 			*cur;
	int					i;
	struct timeval		time;
	unsigned long long	start_t;

	if (!check_fill_opts(argc, argv, &opts))
		return (1);
	head = philo_new(opts, -1, 0);
	if (!head)
		return (1);
	gettimeofday(&time, NULL);
	start_t = (unsigned long long)time.tv_usec;
	start_t += (unsigned long long)time.tv_sec * 1000000;
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(&head, philo_new(opts, i, start_t)))
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
