/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:52:44 by ghan              #+#    #+#             */
/*   Updated: 2021/10/15 15:49:38 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	monitor_end(t_philo *cur, t_opt opts, int *vital)
{
	while (1)
	{
		if (cur->last_eat_t + opts.time_die <= get_now())
		{
			pthread_mutex_lock(cur->print_m);
			printf("\033[31;1m%ld\033[0mms %d died\n",
				time_cal(cur->start_t), cur->idx);
			*vital = ADIOS_PHILO;
			break ;
		}
		if (opts.n_must_eat > 0 && cur->n_eat > opts.n_must_eat)
		{
			*vital = FULL_STOMACH;
			break ;
		}
		cur = cur->next;
	}
}

void	monitor_death(t_philo *cur, t_opt opts,
				pthread_mutex_t *print_m, int *vital)
{
	monitor_end(cur, opts, vital);
	while (--opts.n_philo >= 0)
	{
		pthread_join(cur->tid, NULL);
		cur = cur->next;
	}
	pthread_mutex_destroy(print_m);
}

static void	odd_philos_start(t_philo *cur, t_opt opts, int *vital)
{
	int	i;

	i = -1;
	while (++i < opts.n_philo)
	{
		if (cur->idx % 2)
		{
			if (pthread_create(&(cur->tid), NULL, philo_action, cur))
			{
				*vital = NO_SHOW;
				break ;
			}
		}	
		cur = cur->next;
	}
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
		if (!(cur->idx % 2))
		{
			if (pthread_create(&(cur->tid), NULL, philo_action, cur))
			{
				*vital = NO_SHOW;
				break ;
			}
		}
		cur = cur->next;
	}
	odd_philos_start(cur, opts, vital);	
}
