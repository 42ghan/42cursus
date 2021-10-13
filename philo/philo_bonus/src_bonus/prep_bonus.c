/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:46:58 by ghan              #+#    #+#             */
/*   Updated: 2021/10/14 00:58:29 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	fill_opts(t_opt *opts, char **av)
{
	opts->n_philo = ft_pos_atoi(av[1]);
	opts->time_die = ft_pos_atoi(av[2]) * 1000;
	opts->time_eat = ft_pos_atoi(av[3]) * 1000;
	opts->time_slp = ft_pos_atoi(av[4]) * 1000;
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

int	prep_the_table(t_philo **head, t_opt opts, sem_t *print_s, sem_t *forks_s)
{
	sem_unlink("forks");
	forks_s = sem_open("forks", O_CREAT, S_IRUSR | S_IWUSR, opts.n_philo);
	sem_unlink("print");
	print_s = sem_open("print", O_CREAT, S_IRUSR | S_IWUSR, 1);
	*head = philo_new(opts, NULL, -1, NULL);
	if (!(*head) || !init_philo_profile(*head, opts, print_s, forks_s))
	{
		ft_putendl_fd("Error : malloc failed", STDERR_FILENO);
		free_alloc(*head, print_s, forks_s);
		return (0);
	}
	return (1);
}
