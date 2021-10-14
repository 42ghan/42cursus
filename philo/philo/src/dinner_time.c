/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:52:44 by ghan              #+#    #+#             */
/*   Updated: 2021/10/14 12:24:25 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	monitor_end(t_philo **cur, t_opt opts)
{
	int	i;

	i = -1;
	while (++i < opts.n_philo)
	{
		if ((*cur)->last_eat_t + opts.time_die <= get_now())
			return (ADIOS_PHILO);
		if (*((*cur)->n_eat) >= opts.n_must_eat * opts.n_philo
			&& opts.n_must_eat > 0)
			return (FULL_STOMACH);
		*cur = (*cur)->next;
	}
	return (0);
}

void	monitor_death(t_philo *cur, t_opt opts,
				pthread_mutex_t *print_m, int *vital)
{
	while (*vital == ENJOY_WHILE_ALIVE)
	{
		*vital = monitor_end(&cur, opts);
		if (*vital)
		{
			if (*vital == 1)
			{
				pthread_mutex_lock(print_m);
				printf("\033[31;1m%ld\033[0mms %d died\n",
					time_cal(cur->start_t), cur->idx);
			}
		}
	}
	while (--opts.n_philo >= 0)
	{
		pthread_join(cur->tid, NULL);
		cur = cur->next;
	}
	pthread_mutex_destroy(print_m);
}

void	start_dinner(t_philo *cur, t_opt opts, long start_t, int *vital)
{
	int	i;

	*vital = ENJOY_WHILE_ALIVE;
	i = -1;
	while (++i < opts.n_philo)
	{
		cur->start_t = start_t;
		cur->last_eat_t = start_t;
		cur->vital = vital;
		if (pthread_create(&(cur->tid), NULL, philo_action, cur))
		{
			*vital = NO_SHOW;
			break ;
		}	
		cur = cur->next;
		if (cur->idx % 2 == 1)
			ft_usleep(50);
	}
}
