/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:29:24 by ghan              #+#    #+#             */
/*   Updated: 2021/08/31 19:29:25 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_now(void)
{
	struct timeval	now;
	long			ret;

	gettimeofday(&now, NULL);
	ret = (long)now.tv_sec * 1000000 + (long)now.tv_usec;
	return (ret);
}

long	time_cal(long start_t)
{
	long	ret;

	ret = (get_now() - start_t) / 1000;
	return (ret);
}

static int	ft_usleep(long interval)
{
	long	end;

	end = interval + get_now();
	while (end > get_now())
		usleep(50);
	return (1);
}

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork));
	pthread_mutex_lock(&(philo->next->fork));
	pthread_mutex_lock(philo->print_m);
	printf("\033[31;1m%ld\033[0mms %d has taken a fork\n",
		time_cal(philo->start_t), philo->idx);
	pthread_mutex_unlock(philo->print_m);
	pthread_mutex_lock(philo->print_m);
	printf("\033[31;1m%ld\033[0mms %d has taken a fork\n",
		time_cal(philo->start_t), philo->idx);
	pthread_mutex_unlock(philo->print_m);
	pthread_mutex_lock(philo->print_m);
	*(philo->n_eat) += 1;
	printf("\033[31;1m%ld\033[0mms %d is eating\n",
		time_cal(philo->start_t), philo->idx);
	if (philo->opts.n_must_eat < 0)
		pthread_mutex_unlock(philo->print_m);
	else if (*(philo->n_eat) < philo->opts.n_philo * philo->opts.n_must_eat)
		pthread_mutex_unlock(philo->print_m);
	philo->last_eat_t = get_now();
	ft_usleep(philo->opts.time_eat * 1000);
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
		pthread_mutex_lock(philo->print_m);
		printf("\033[31;1m%ld\033[0mms %d is sleeping\n",
			time_cal(philo->start_t), philo->idx);
		pthread_mutex_unlock(philo->print_m);
		ft_usleep(philo->opts.time_slp * 1000);
		pthread_mutex_lock(philo->print_m);
		printf("\033[31;1m%ld\033[0mms %d is thinking\n",
			time_cal(philo->start_t), philo->idx);
		pthread_mutex_unlock(philo->print_m);
	}
	return (NULL);
}
