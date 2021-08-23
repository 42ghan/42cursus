/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:27:51 by ghan              #+#    #+#             */
/*   Updated: 2021/07/05 17:27:51 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	elem_to_top(t_head *head, t_stack *elem)
{
	head->start->prev->next = elem;
	elem->prev = head->start->prev;
	elem->next = head->start;
	head->start->prev = elem;
}

static t_stack	*init_stack_elem(int nbr)
{
	t_stack	*elem;

	elem = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!elem)
		error_exit(2);
	elem->nbr = nbr;
	elem->idx = -1;
	return (elem);
}

void	init_stack(t_head *head, int *nbrs)
{
	int		i;
	t_stack	*cur;

	if (nbrs)
	{
		i = nbrs[0];
		while (i >= 1)
		{
			cur = init_stack_elem(nbrs[i]);
			if (i == nbrs[0])
			{
				head->start = cur;
				cur->next = cur;
				cur->prev = cur;
			}
			else
				elem_to_top(head, cur);
			i--;
		}
	}
	else
		head->start = NULL;
}
