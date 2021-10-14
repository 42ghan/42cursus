/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:49:02 by ghan              #+#    #+#             */
/*   Updated: 2021/10/14 17:21:55 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fill_opts(t_opt *opts, char **av)
{
	opts->n_philo = ft_pos_atoi(av[1]);
	opts->time_die = (long)ft_pos_atoi(av[2]) * 1000;
	opts->time_eat = (long)ft_pos_atoi(av[3]) * 1000;
	opts->time_slp = (long)ft_pos_atoi(av[4]) * 1000;
}

int	check_fill_opts(int ac, char **av, t_opt *opts)
{
	if (!(ac == 5 || ac == 6))
	{
		ft_putendl_fd("Error : Wrong number of ARGV", STDERR_FILENO);
		return (0);
	}
	fill_opts(opts, av);
	if (opts->n_philo < 1 || opts->n_philo > 199 || opts->time_die < 0
		|| opts->time_eat < 0 || opts->time_slp < 0)
	{
		ft_putendl_fd("Error : Wrong ARGV", STDERR_FILENO);
		return (0);
	}
	opts->n_must_eat = -1;
	if (ac == 6)
	{
		opts->n_must_eat = ft_pos_atoi(av[5]);
		if (opts->n_must_eat < 0)
		{
			ft_putendl_fd("Error : Wrong ARGV", STDERR_FILENO);
			return (0);
		}
	}
	return (1);
}

static int	init_fork_mutexes(t_philo *cur)
{
	int	i;

	i = -1;
	while (++i < cur->opts.n_philo)
	{
		if (pthread_mutex_init(&(cur->fork), NULL))
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	prepare_the_table(t_philo **head, t_opt opts, pthread_mutex_t *print_m)
{
	if (pthread_mutex_init(print_m, NULL))
	{
		ft_putendl_fd("Error : print mutex init failed", STDERR_FILENO);
		return (0);
	}
	*head = philo_new(opts, NULL);
	if (!(*head) || !init_philo_profile(*head, opts, print_m))
	{
		ft_putendl_fd("Error : malloc failed", STDERR_FILENO);
		free_alloc(*head);
		pthread_mutex_destroy(print_m);
		return (0);
	}
	if (!init_fork_mutexes((*head)->next))
	{
		ft_putendl_fd("Error : fork mutex init failed", STDERR_FILENO);
		free_alloc(*head);
		pthread_mutex_destroy(print_m);
		return (0);
	}
	return (1);
}
