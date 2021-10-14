/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:44:54 by ghan              #+#    #+#             */
/*   Updated: 2021/10/14 17:51:53 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	dinner_is_over(t_philo *cur, int n_philo)
{
	ft_putendl_fd("Error : no show...", STDERR_FILENO);
	while (--n_philo >= 0)
	{
		kill(cur->pid, SIGINT);
		cur = cur->next;
	}
	sem_close(cur->forks);
	sem_unlink("forks");
	sem_close(cur->print_s);
	sem_unlink("print");
	exit(EXIT_FAILURE);
}

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
		else if ((*cur)->pid < 0)
			break ;
		*cur = (*cur)->next;
	}
	if ((*cur)->pid < 0)
		dinner_is_over(*cur, (*cur)->opts.n_philo);
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
		if (pthread_create(&(cur->monitor), NULL, monitor_end, cur))
		{
			ft_putendl_fd("Error : philo failed to create a monitor thread",
				STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
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
