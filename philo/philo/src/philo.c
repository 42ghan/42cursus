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
			return (0);
	}
	return (1);
}

static t_philo	*init_philos(t_opt opts, int *n_eat, int *v_flag,
	pthread_mutex_t *vital_m)
{
	t_philo	*head;
	int		i;

	head = philo_new(opts, NULL, NULL, NULL);
	if (!head)
		return (NULL);
	head->next = NULL;
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(&head, philo_new(opts, n_eat, v_flag, vital_m), i))
			return (NULL);
	}
	return (head);
}

static void	create_and_join(t_philo *head, t_opt opts)
{
	t_philo	*cur;
	long	start_t;
	int		i;

	start_t = get_now();
	cur = head->next;
	i = -1;
	while (++i < opts.n_philo)
	{
		cur->start_t = start_t;
		cur->last_eat_t = start_t;
		pthread_create(&(cur->tid), NULL, philo_action, cur);
		pthread_create(&(cur->monitor), NULL, monitor_death, cur);
		cur = cur->next;
		usleep(10);
	}
	i = -1;
	while (++i < opts.n_philo)
	{
		pthread_join(cur->monitor, NULL);
		pthread_detach(cur->tid);
		cur = cur->next;
	}
}

int	main(int argc, char *argv[])
{
	pthread_mutex_t	vital_m;
	int				v_flag;
	int				n_eat;
	t_opt			opts;
	t_philo			*head;

	if (!check_fill_opts(argc, argv, &opts))
	{
		write(2, "Error : Wrong ARGV\n", 19);
		return (1);
	}
	v_flag = 0;
	n_eat = 0;
	pthread_mutex_init(&vital_m, NULL);
	head = init_philos(opts, &n_eat, &v_flag, &vital_m);
	if (!head)
		return (1);
	create_and_join(head, opts);
	free_alloc(head, opts.n_philo);
	return (0);
}
