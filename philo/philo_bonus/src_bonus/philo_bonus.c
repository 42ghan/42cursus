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
	opts->n_philo = ft_atoi(av[1]);
	opts->time_die = ft_atoi(av[2]);
	opts->time_eat = ft_atoi(av[3]);
	opts->time_slp = ft_atoi(av[4]);
	if (opts->n_philo < 1 || opts->time_die < 0
		|| opts->time_eat < 0 || opts->time_slp < 0)
		return (0);
	opts->n_must_eat = -1;
	if (ac == 6)
	{
		opts->n_must_eat = ft_atoi(av[5]);
		if (opts->n_must_eat < 0)
			return (0);
	}
	return (1);
}

t_philo	*philo_new(t_opt opts)
{
	t_philo	*elem;

	elem = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!elem)
		return (NULL);
	elem->opts = opts;
	return (elem);
}

int	philo_addback(t_philo **head, t_philo *new, int idx)
{
	t_philo	*cur;

	if (!new)
		return (0);
	if (!(*head)->next)
	{
		(*head)->next = new;
		new->next = new;
	}
	cur = (*head)->next;
	while (cur->next != (*head)->next)
		cur = cur->next;
	cur->next = new;
	new->next = (*head)->next;
	new->idx = idx;
	return (1);
}

static t_philo	*init_philos(t_opt opts)
{
	t_philo	*head;
	int		i;

	head = philo_new(opts);
	if (!head)
		return (NULL);
	head->next = NULL;
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(&head, philo_new(opts), i))
			return (NULL);
	}
	return (head);
}

// static void *birth_to_child(void *arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;
// 	philo->pid = fork();
// 	return (NULL);
// }

static void	create_to_fork(t_philo *head, t_opt opts)
{
	t_philo	*cur;
	long	start_t;
	int		i;

	start_t = get_now();
	cur = head->next;
	i = -1;
	while (++i < opts.n_philo)
	{
		cur->start_t = start_t;
		cur->last_eat_t = start_t;
		// pthread_create(&(cur->tid), NULL, birth_to_child, cur);
		// pthread_detach(cur->tid);
		cur->pid = fork();
		cur = cur->next;
		// usleep(10);
	}
	// i = -1;
	// while (++i < opts.n_philo)
	// {
	// 	pthread_join(cur->tid, NULL);
	// 	// waitpid(cur->pid, NULL, 0);
	// 	cur = cur->next;
	// }
}

int main(int argc, char *argv[])
{
	t_opt		opts;
	t_philo		*head;

	if (!check_fill_opts(argc, argv, &opts))
	{
		write(2, "Error : Wrong ARGV\n", 19);
		return (1);
	}
	head = init_philos(opts);
	if (!head)
		return (1);
	create_to_fork(head, opts);
		printf("hello\n");
	while (1)
		;
	return (0);
}
