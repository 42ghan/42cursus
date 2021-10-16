/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:29:24 by ghan              #+#    #+#             */
/*   Updated: 2021/10/15 22:06:38 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_stat(char *status, t_philo *philo)
{
	if (*philo->vital)
		return ;
	pthread_mutex_lock(philo->print_m);
	if (*philo->vital == ENJOY_WHILE_ALIVE)
	{
		printf("\033[31;1m%ld\033[0mms ", time_cal(philo->start_t));
		printf("%d %s\n", philo->idx, status);
	}
	pthread_mutex_unlock(philo->print_m);
}

static void	print_eat(char *status, t_philo *philo)
{
	if (*philo->vital)
		return ;
	pthread_mutex_lock(philo->print_m);
	if (*philo->vital == ENJOY_WHILE_ALIVE)
	{
		philo->n_eat++;
		philo->last_eat_t = get_now();
		printf("\033[31;1m%ld\033[0mms ", time_cal(philo->start_t));
		printf("%d %s\n", philo->idx, status);
	}
	if (philo->opts.n_must_eat < 0)
		pthread_mutex_unlock(philo->print_m);
	else if (philo->n_eat <= philo->opts.n_must_eat)
		pthread_mutex_unlock(philo->print_m);
	ft_usleep(philo->opts.time_eat);
}

void	*philo_action(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!(philo->idx % 2))
		ft_usleep(philo->opts.time_eat / 2);
	while (*philo->vital == ENJOY_WHILE_ALIVE)
	{
		pthread_mutex_lock(&(philo->fork));
		print_stat("has taken a fork", philo);
		pthread_mutex_lock(&(philo->next->fork));
		print_stat("has taken a fork", philo);
		print_eat("is eating", philo);
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->fork));
		print_stat("is sleeping", philo);
		ft_usleep(philo->opts.time_slp);
		print_stat("is_thinking", philo);
	}
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(philo->print_m);
	return (NULL);
}

void	*mr_lonely(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->fork));
	print_stat("has taken a fork", philo);
	while (*philo->vital == ENJOY_WHILE_ALIVE)
		usleep(100);
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(philo->print_m);
	return (NULL);
}
