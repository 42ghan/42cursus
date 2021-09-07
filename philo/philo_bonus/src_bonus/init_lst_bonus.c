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

t_philo	*philo_new(t_opt opts, int *n_eat, sem_t *print_s, int idx)
{
	t_philo	*elem;
	char	*sem_name;

	elem = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!elem)
		return (NULL);
	elem->idx = idx;
	elem->n_eat = n_eat;
	elem->opts = opts;
	elem->print_s = print_s;
	if (idx >= 0)
	{
		sem_name = ft_pos_itoa(idx);
		if (!sem_name)
			return (NULL);
		elem->fork = sem_open(sem_name, O_CREAT, S_IRUSR | S_IWUSR, 1);
		free(sem_name);
	}
	return (elem);
}

static int	philo_addback(t_philo **head, t_philo *new)
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
	return (1);
}

int	init_philo_profile(t_philo **head, t_opt opts, int *n_eat, sem_t *print_s)
{
	int	i;

	if (!(*head))
		return (0);
	(*head)->next = NULL;
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(head, philo_new(opts, n_eat, print_s, i)))
			return (0);
	}
	return (1);
}