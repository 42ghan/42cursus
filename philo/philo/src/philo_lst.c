/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:39:24 by ghan              #+#    #+#             */
/*   Updated: 2021/10/14 15:24:35 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_new(t_opt opts, pthread_mutex_t *print_m)
{
	t_philo	*elem;

	elem = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!elem)
		return (NULL);
	elem->n_eat = 0;
	elem->print_m = print_m;
	elem->opts = opts;
	return (elem);
}

static int	philo_addback(t_philo *head, t_philo *new, int idx)
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
	new->idx = idx;
	return (1);
}

int	init_philo_profile(t_philo *head, t_opt opts, pthread_mutex_t *print_m)
{
	int	i;

	if (!head)
		return (0);
	head->next = NULL;
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(head, philo_new(opts, print_m), i))
			return (0);
	}
	return (1);
}
