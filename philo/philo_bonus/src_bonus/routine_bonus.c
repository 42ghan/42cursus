/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:27:44 by ghan              #+#    #+#             */
/*   Updated: 2021/09/07 16:27:45 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl_bonus/philo_bonus.h"

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
	sem_wait(philo->fork);
	sem_wait(philo->next->fork);
	sem_wait(philo->print_s);
	printf("\033[31;1m%ld\033[0mms %d has taken a fork\n",
		time_cal(philo->start_t), philo->idx);
	sem_post(philo->print_s);
	sem_wait(philo->print_s);
	printf("\033[31;1m%ld\033[0mms %d has taken a fork\n",
		time_cal(philo->start_t), philo->idx);
	sem_post(philo->print_s);
	sem_wait(philo->print_s);
	*(philo->n_eat) += 1;
	printf("\033[31;1m%ld\033[0mms %d is eating\n",
		time_cal(philo->start_t), philo->idx);
	if (philo->opts.n_must_eat < 0)
		sem_post(philo->print_s);
	else if (*(philo->n_eat)
		< philo->opts.n_philo * philo->opts.n_must_eat)
		sem_post(philo->print_s);
	philo->last_eat_t = get_now();
	ft_usleep(philo->opts.time_eat * 1000);
	sem_post(philo->fork);
	sem_post(philo->next->fork);
}

void	start_dinner(t_philo *philo)
{
	while (1)
	{
		philo_eat(philo);
		sem_wait(philo->print_s);
		printf("\033[31;1m%ld\033[0mms %d is sleeping\n",
			time_cal(philo->start_t), philo->idx);
		sem_post(philo->print_s);
		ft_usleep(philo->opts.time_slp * 1000);
		sem_wait(philo->print_s);
		printf("\033[31;1m%ld\033[0mms %d is thinking\n",
			time_cal(philo->start_t), philo->idx);
		sem_post(philo->print_s);
	}
}
