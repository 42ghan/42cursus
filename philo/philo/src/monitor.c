/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:58:12 by ghan              #+#    #+#             */
/*   Updated: 2021/10/17 23:40:25 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	monitor_end(t_philo *cur, t_opt opts, int *vital, int cnt_eat)
{
	while (1)
	{
		if (cur->last_eat_t + opts.time_die <= get_now())
		{
			pthread_mutex_lock(cur->print_m);
			printf("\033[31;1m%ld\033[0mms %d died\n",
				time_cal(cur->start_t), cur->idx);
			*vital = ADIOS_PHILO;
		}
		if (opts.n_must_eat > 0 && cur->n_eat >= opts.n_must_eat)
		{
			if (cur->check_eat == NOT_YET)
			{
				cnt_eat++;
				cur->check_eat = CHECKED;
			}
			if (cnt_eat >= opts.n_philo)
				*vital = FULL_STOMACH;
		}
		if (*vital)
			break ;
		cur = cur->next;
		usleep(100);
	}
}

void	monitor_death(t_philo *cur, t_opt opts,
				pthread_mutex_t *print_m, int *vital)
{
	monitor_end(cur, opts, vital, 0);
	while (--opts.n_philo >= 0)
	{
		pthread_join(cur->tid, NULL);
		cur = cur->next;
	}
	pthread_mutex_destroy(print_m);
}
