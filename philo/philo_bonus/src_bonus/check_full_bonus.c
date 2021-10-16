/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_full_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:40:10 by ghan              #+#    #+#             */
/*   Updated: 2021/10/16 16:00:06 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*cnt_eat(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = -1;
	while (++i < philo->opts.n_philo)
		sem_wait(philo->full_s);
	return (NULL);
}

int	check_full(t_philo *philo, pthread_t *full_thrd)
{
	if (pthread_create(full_thrd, NULL, cnt_eat, philo))
	{
		kill_philos(philo, philo->opts.n_philo);
		ft_putendl_fd("Error : failed to create a full check thread",
			STDERR_FILENO);
		return (0);
	}
	return (1);
}
