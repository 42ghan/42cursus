/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:49:02 by ghan              #+#    #+#             */
/*   Updated: 2021/10/13 21:51:22 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fill_opts(t_opt *opts, char **av)
{
	opts->n_philo = ft_pos_atoi(av[1]);
	opts->time_die = ft_pos_atoi(av[2]);
	opts->time_eat = ft_pos_atoi(av[3]);
	opts->time_slp = ft_pos_atoi(av[4]);
}

int	check_fill_opts(int ac, char **av, t_opt *opts)
{
	if (!(ac == 5 || ac == 6))
	{
		ft_putendl_fd("Error : Wrong number of ARGV", STDERR_FILENO);
		return (0);
	}
	fill_opts(opts, av);
	if (opts->n_philo < 1 || opts->time_die < 0
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

int	prepare_the_table(t_philo **head, t_opt opts, int *n_eat,
		pthread_mutex_t *print_m)
{
	*n_eat = 0;
	pthread_mutex_init(print_m, NULL);
	*head = philo_new(opts, NULL, NULL);
	if (!(*head) || !init_philo_profile(*head, opts, n_eat, print_m))
	{
		ft_putendl_fd("Error : malloc failed", STDERR_FILENO);
		free_alloc(*head);
		return (0);
	}
	return (1);
}
