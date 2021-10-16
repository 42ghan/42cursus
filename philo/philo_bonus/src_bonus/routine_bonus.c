/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:27:44 by ghan              #+#    #+#             */
/*   Updated: 2021/10/16 16:04:53 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	print_stat(char *status, t_philo *philo)
{
	sem_wait(philo->print_s);
	printf("\033[31;1m%ld\033[0mms ", time_cal(philo->start_t));
	printf("%d %s\n", philo->idx, status);
	sem_post(philo->print_s);
}

void	have_dinner(t_philo *philo)
{
	int	eat_cnt;

	eat_cnt = 0;
	while (1)
	{
		sem_wait(philo->forks);
		print_stat("has taken a fork", philo);
		sem_wait(philo->forks);
		print_stat("has taken a fork", philo);
		print_stat("is eating", philo);
		if (philo->opts.n_must_eat > 0)
		{
			eat_cnt++;
			if (eat_cnt == philo->opts.n_must_eat)
				sem_post(philo->full_s);
		}
		philo->last_eat_t = get_now();
		ft_usleep(philo->opts.time_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		print_stat("is sleeping", philo);
		ft_usleep(philo->opts.time_slp);
		print_stat("is thinking", philo);
	}
}
