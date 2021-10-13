/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:44:54 by ghan              #+#    #+#             */
/*   Updated: 2021/10/13 22:58:40 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	create_philos(t_philo **cur, t_opt opts)
{
	long	start_t;
	int		i;

	start_t = get_now();
	i = -1;
	while (++i < opts.n_philo)
	{
		(*cur)->start_t = start_t;
		(*cur)->last_eat_t = start_t;
		(*cur)->pid = fork();
		if (!((*cur)->pid))
			return ;
		*cur = (*cur)->next;
	}
}

static void	*monitor_end(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->last_eat_t + philo->opts.time_die > get_now())
		usleep(10);
	sem_wait(philo->print_s);
	printf("\033[31;1m%ld\033[0mms %d died\n",
		time_cal(philo->start_t), philo->idx);
	exit(EXIT_FAILURE);
	return (NULL);
}

void	dine_with_fork(t_philo *cur, t_opt opts)
{
	create_philos(&cur, opts);
	if (!(cur->pid))
	{
		pthread_create(&(cur->monitor), NULL, monitor_end, cur);
		have_dinner(cur);
		pthread_join(cur->monitor, NULL);
	}
	else
	{
		waitpid(-1, NULL, 0);
		while (--opts.n_philo >= 0)
		{
			kill(cur->pid, SIGINT);
			cur = cur->next;
		}
	}
}
