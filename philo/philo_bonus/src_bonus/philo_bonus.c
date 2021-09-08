/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:11:47 by ghan              #+#    #+#             */
/*   Updated: 2021/09/03 11:11:48 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl_bonus/philo_bonus.h"

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
			break ;
		*cur = (*cur)->next;
	}
}

static void	kill_children(t_philo *cur, int n)
{
	while (--n >= 0)
	{
		kill(cur->pid, 9);
		cur = cur->next;
	}
}

static void	*monitor_end(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->last_eat_t + philo->opts.time_die * 1000 > get_now())
	{
		usleep(1);
	}
	printf("\033[31;1m%ld\033[0mms %d died\n",
		time_cal(philo->start_t), philo->idx);
	exit(1);
	return (NULL);
}

static void	dine_with_fork(t_philo *cur, t_opt opts)
{
	create_philos(&cur, opts);
	if (!(cur->pid))
	{
		pthread_create(&(cur->monitor), NULL, monitor_end, cur);
		start_dinner(cur);
		pthread_join(cur->monitor, NULL);
	}
	else
	{
		waitpid(-1, NULL, 0);
		kill_children(cur, opts.n_philo);
	}
	// {
	// 	while (1)
	// 	{
	// 		vital = monitor_end(&cur, opts);
	// 		if (vital)
	// 		{
	// 			if (vital == 1)
	// 			{
	// 				sem_wait(cur->print_s);
	// 				printf("\033[31;1m%ld\033[0mms %d died\n",
	// 					time_cal(cur->start_t), cur->idx);
	// 			}
	// 			kill_children(cur, opts.n_philo);
	// 			break ;
	// 		}
	// 	}
	// }
}

int	main(int argc, char *argv[])
{
	t_opt		opts;
	t_philo		*head;
	sem_t		*print_s;
	int			n_eat;

	if (!check_fill_opts(argc, argv, &opts))
	{
		write(2, "Error : Wrong ARGV\n", 19);
		return (1);
	}
	n_eat = 0;
	sem_unlink("print_s");
	print_s = sem_open("print_s", O_CREAT, S_IRUSR | S_IWUSR, 1);
	head = philo_new(opts, NULL, NULL, -1);
	if (!head || !init_philo_profile(head, opts, &n_eat, print_s))
	{
		write(2, "Error : malloc failed\n", 22);
		free_alloc(head);
		return (1);
	}
	dine_with_fork(head->next, opts);
	sem_close(print_s);
	free_alloc(head);
	return (0);
}
