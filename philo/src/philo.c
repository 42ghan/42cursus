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

static t_philo	*philo_new(t_opt opts, int i)
{
	t_philo	*elem;

	elem = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!elem)
		return (NULL);
	elem->nth = i;
	elem->n_eat = 0;
	elem->cur_act = 's';
	elem->opts = opts;
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

static void	*philo_action(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	// while (1)
	// {
		pthread_mutex_lock(&(philo->fork));
		pthread_mutex_lock(&(philo->next->fork));
		printf("%d has taken a fork\n", philo->nth);
		printf("%d is eating\n", philo->nth);
		usleep(philo->opts.time_eat);
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->fork));
		printf("%d is sleeping\n", philo->nth);
		usleep(philo->opts.time_slp);
		printf("%d is thinking\n", philo->nth);
	// }
	return (NULL);
}

/* TODO ==============================
- make time cal. function
- death check system
====================================*/

int	main(int argc, char *argv[])
{
	t_opt	opts;
	t_philo	*head;
	t_philo *cur;
	int		i;

	if (!check_fill_opts(argc, argv, &opts))
		return (1);
	head = philo_new(opts, -1);
	if (!head)
		return (1);
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(&head, philo_new(opts, i)))
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
