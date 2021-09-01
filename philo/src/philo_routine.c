/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:29:24 by ghan              #+#    #+#             */
/*   Updated: 2021/08/31 19:29:25 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static long	time_cal(long start_t)
{
	long	ret;

	ret = (get_now() - start_t) / 1000;
	return (ret);
}

void	*monitor_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (*(philo->v_flag) == 0
		&& philo->last_eat_t + philo->opts.time_die * 1000 > get_now())
	{
		if (philo->opts.n_must_eat > 0
			&& philo->n_eat >= philo->opts.n_must_eat)
		{
			*(philo->v_flag) = 1;
			break ;
		}
		usleep(1);
	}
	pthread_mutex_lock(philo->vital_m);
	if (*(philo->v_flag) == 0)
	{
		*(philo->v_flag) = 1;
		printf("\033[31;1m%ld\033[0mms %d died\n",
			time_cal(philo->start_t), philo->idx);
	}
	pthread_mutex_unlock(philo->vital_m);
	return (NULL);
}

static int	ft_usleep(long interval)
{
	long	end;

	end = interval + get_now();
	while (end > get_now())
		usleep(1);
	return (1);
}

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	pthread_mutex_lock(&(philo->next->fork));
	printf("\033[31;1m%ld\033[0mms %d has taken a fork\n",
		time_cal(philo->start_t), philo->idx);
	printf("\033[31;1m%ld\033[0mms %d has taken a fork\n",
		time_cal(philo->start_t), philo->idx);
	philo->last_eat_t = get_now();
	printf("\033[31;1m%ld\033[0mms %d is eating\n",
		time_cal(philo->start_t), philo->idx);
	ft_usleep(philo->opts.time_eat * 1000);
	(philo->n_eat)++;
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(&(philo->next->fork));
}

void	*philo_action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		philo_eat(philo);
		printf("\033[31;1m%ld\033[0mms %d is sleeping\n",
			time_cal(philo->start_t), philo->idx);
		ft_usleep(philo->opts.time_slp * 1000);
		printf("\033[31;1m%ld\033[0mms %d is thinking\n",
			time_cal(philo->start_t), philo->idx);
	}
	return (NULL);
}
