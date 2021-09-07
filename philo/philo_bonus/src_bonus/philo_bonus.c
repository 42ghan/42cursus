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

static int	check_fill_opts(int ac, char **av, t_opt *opts)
{
	if (!(ac == 5 || ac == 6))
		return (0);
	opts->n_philo = ft_pos_atoi(av[1]);
	opts->time_die = ft_pos_atoi(av[2]);
	opts->time_eat = ft_pos_atoi(av[3]);
	opts->time_slp = ft_pos_atoi(av[4]);
	if (opts->n_philo < 1 || opts->time_die < 0
		|| opts->time_eat < 0 || opts->time_slp < 0)
		return (0);
	opts->n_must_eat = -1;
	if (ac == 6)
	{
		opts->n_must_eat = ft_pos_atoi(av[5]);
		if (opts->n_must_eat < 0)
			return (0);
	}
	return (1);
}

static void	create_philos(t_philo **cur, t_opt opts, long start_t)
{
	int	i;

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

// static void	monitor_end(t_philo *cur)
// {

// }

static void	dine_with_fork(t_philo *head, t_opt opts)
{
	t_philo	*cur;
	long	start_t;
	int		i;

	start_t = get_now();
	cur = head->next;
	create_philos(&cur, opts, start_t);
	if (!(cur->pid))
		start_dinner(cur);
	else
	{
		sleep(5);
		i = -1;
		while (++i < opts.n_philo)
		{
			kill(cur->pid, 9);
			cur = cur->next;
		}
	}
	// 	monitor_end(cur);
}

int main(int argc, char *argv[])
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
	print_s = sem_open("print_s", O_CREAT, S_IRUSR | S_IWUSR, 1);
	head = philo_new(opts, NULL, NULL, -1);
	if (!head || !init_philo_profile(&head, opts, &n_eat, print_s))
	{
		write(2, "Error : malloc failed\n", 22);
		free_alloc(head);
		return (1);
	}
	dine_with_fork(head, opts);
	sem_close(print_s);
	free_alloc(head);
	return (0);
}
