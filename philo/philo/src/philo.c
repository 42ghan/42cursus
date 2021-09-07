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
	opts->n_philo = ft_pos_atoi(av[1]);
	opts->time_die = ft_pos_atoi(av[2]);
	opts->time_eat = ft_pos_atoi(av[3]);
	opts->time_slp = ft_pos_atoi(av[4]);
	if (opts->n_philo < 1 || opts->time_die < 0
		|| opts->time_eat < 0 || opts->time_slp < 0)
		return (0);
	opts->n_must_eat = -1;
	if (ac == 6)
	{
		opts->n_must_eat = ft_pos_atoi(av[5]);
		if (opts->n_must_eat < 0)
			return (0);
	}
	return (1);
}

static int	monitor_end(t_philo **cur, t_opt opts)
{
	int	i;

	i = -1;
	while (++i < opts.n_philo)
	{
		if ((*cur)->last_eat_t + opts.time_die * 1000 <= get_now())
			return (1);
		if (*((*cur)->n_eat) >= opts.n_must_eat * opts.n_philo
			&& opts.n_must_eat > 0)
			return (2);
		*cur = (*cur)->next;
	}
	return (0);
}

static void	start_dinner(t_philo *cur, t_opt opts, long start_t)
{
	int	i;

	i = -1;
	while (++i < opts.n_philo)
	{
		cur->start_t = start_t;
		cur->last_eat_t = start_t;
		pthread_create(&(cur->tid), NULL, philo_action, cur);
		cur = cur->next;
		if (cur->idx % 2 == 1)
			usleep(20);
	}
}

static void	dine_or_die(t_philo *cur, t_opt opts, pthread_mutex_t *print_m)
{
	long	start_t;
	int		vital;

	start_t = get_now();
	start_dinner(cur, opts, start_t);
	while (1)
	{
		vital = monitor_end(&cur, opts);
		if (vital)
		{
			if (vital == 1)
			{
				pthread_mutex_lock(print_m);
				printf("\033[31;1m%ld\033[0mms %d died\n",
					time_cal(cur->start_t), cur->idx);
			}
			while (--opts.n_philo >= 0)
			{
				pthread_detach(cur->tid);
				cur = cur->next;
			}
			break ;
		}
	}
}

int	main(int argc, char *argv[])
{
	pthread_mutex_t	print_m;
	int				n_eat;
	t_opt			opts;
	t_philo			*head;

	if (!check_fill_opts(argc, argv, &opts))
	{
		write(2, "Error : Wrong ARGV\n", 19);
		return (1);
	}
	n_eat = 0;
	pthread_mutex_init(&print_m, NULL);
	head = philo_new(opts, NULL, NULL);
	if (!head || !init_philo_profile(&head, opts, &n_eat, &print_m))
	{
		write(2, "Error : malloc failed\n", 22);
		free_alloc(head);
		return (1);
	}
	dine_or_die(head->next, opts, &print_m);
	pthread_mutex_destroy(&print_m);
	free_alloc(head);
	return (0);
}
