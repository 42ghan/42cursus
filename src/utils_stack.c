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

t_stack	*stack_pop(t_head **head)
{
	t_stack	*top;

	top = (*head)->start->prev;
	(*head)->start->prev = top->prev;
	top->prev->next = (*head)->start;
	return (top);
}

void	elem_to_top(t_head **head, t_stack *elem)
{
	elem->prev = (*head)->start->prev;
	elem->next = (*head)->start;
	(*head)->start->prev->next = elem;
	(*head)->start->prev = elem;
}

static t_stack	*init_stack_elem(int nbr)
{
	t_stack	*elem;

	elem = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!elem)
		error_exit(2);
	elem->nbr = nbr;
	return (elem);
}

void	init_stack(t_head **head, int *nbrs)
{
	int		i;
	t_stack	*cur;

	*head = (t_head *)ft_calloc(1, sizeof(t_head));
	if (!(*head))
		error_exit(2);
	if (nbrs)
	{
		i = 0;
		while (++i < nbrs[0] + 1)
		{
			cur = init_stack_elem(nbrs[i]);
			if (i == 1)
			{
				(*head)->start = cur;
				cur->next = cur;
				cur->prev = cur;
			}
			else
				elem_to_top(head, cur);
		}
	}
	else
		(*head)->start = NULL;
}
