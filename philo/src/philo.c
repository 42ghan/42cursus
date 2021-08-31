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
	{
		write(2, "Error : wrong no. of arguments\n", 31);
		return (0);
	}
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
			return (0);
	}
	return (1);
}

static void	create_and_join(t_philo *head, t_opt opts)
{
	t_philo	*cur;
	int		i;

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
}

static t_philo	*init_philos(t_opt opts)
{
	t_philo			*head;
	pthread_mutex_t	vital_m;
	long			start_t;
	int				v_flag;
	int				i;

	head = philo_new(opts, 0, NULL, NULL);
	if (!head)
		return (NULL);
	head->next = NULL;
	v_flag = 0;
	start_t = get_now();
	pthread_mutex_init(&vital_m, NULL);
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(&head,
				philo_new(opts, start_t, &v_flag, &vital_m), i))
			return (NULL);
	}
	return (head);
}

int	main(int argc, char *argv[])
{
	t_opt	opts;
	t_philo	*head;

	if (!check_fill_opts(argc, argv, &opts))
		return (1);
	head = init_philos(opts);
	if (!head)
		return (1);
	create_and_join(head, opts);
	free_alloc(head, opts.n_philo);
	return (0);
}
