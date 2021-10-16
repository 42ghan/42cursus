/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:25:00 by ghan              #+#    #+#             */
/*   Updated: 2021/10/14 15:12:45 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*philo_new(t_opt opts, sem_t *print_s, int idx, sem_t *forks_s)
{
	t_philo	*elem;

	elem = (t_philo *)ft_calloc(1, sizeof(t_philo));
	if (!elem)
		return (NULL);
	elem->idx = idx + 1;
	elem->opts = opts;
	elem->print_s = print_s;
	elem->forks = forks_s;
	elem->full_s = NULL;
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

int	init_philo_profile(t_philo *hd, t_opt opts, sem_t *print_s, sem_t *forks_s)
{
	int	i;

	if (!hd)
		return (0);
	hd->next = NULL;
	i = -1;
	while (++i < opts.n_philo)
	{
		if (!philo_addback(hd, philo_new(opts, print_s, i, forks_s)))
			return (0);
	}
	return (1);
}
