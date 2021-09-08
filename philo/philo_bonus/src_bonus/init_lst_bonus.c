/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:25:00 by ghan              #+#    #+#             */
/*   Updated: 2021/09/07 16:25:00 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl_bonus/philo_bonus.h"

t_philo	*philo_new(t_opt opts, sem_t *print_s, int idx)
{
	t_philo	*elem;
	char	*sem_name;

	elem = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!elem)
		return (NULL);
	elem->idx = idx;
	elem->n_eat = 0;
	elem->opts = opts;
	elem->print_s = print_s;
	if (idx >= 0)
	{
		sem_name = ft_pos_itoa(idx);
		if (!sem_name)
			return (NULL);
		sem_unlink(sem_name);
		elem->fork = sem_open(sem_name, O_CREAT, S_IRUSR | S_IWUSR, 1);
		free(sem_name);
	}
	return (elem);
}

static int	philo_addback(t_philo *head, t_philo *new)
{
	t_philo	*cur;

	if (!new)
		return (0);
	if (!head->next)
	{
		head->next = new;
		new->next = new;
	}
	cur = head->next;
	while (cur->next != head->next)
		cur = cur->next;
	cur->next = new;
	new->next = head->next;
	return (1);
}

int	init_philo_profile(t_philo *head, t_opt opts, sem_t *print_s)
{
	int	i;

	if (!head)
		return (0);
	head->next = NULL;
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(head, philo_new(opts, print_s, i)))
			return (0);
	}
	return (1);
}

int	check_fill_opts(int ac, char **av, t_opt *opts)
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
