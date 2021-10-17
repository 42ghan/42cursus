/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:52:44 by ghan              #+#    #+#             */
/*   Updated: 2021/10/17 22:58:00 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	odd_philos_start(t_philo *cur, t_opt opts, int *vital)
{
	int	i;

	if (*vital == NO_SHOW || opts.n_philo == 1)
		return ;
	i = -1;
	while (++i < opts.n_philo)
	{
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
}

void	start_dinner(t_philo *cur, t_opt opts, long start_t, int *vital)
{
	int	i;

	i = -1;
	while (++i < opts.n_philo)
	{
		cur->start_t = start_t;
		cur->last_eat_t = start_t;
		cur->vital = vital;
		if (cur->idx % 2)
		{
			if (opts.n_philo == 1)
			{
				if (pthread_create(&(cur->tid), NULL, mr_lonely, cur))
					*vital = NO_SHOW;
				break ;
			}
			else if (pthread_create(&(cur->tid), NULL, philo_action, cur))
			{
				*vital = NO_SHOW;
				break ;
			}
		}
		cur = cur->next;
	}
	odd_philos_start(cur, opts, vital);
}
