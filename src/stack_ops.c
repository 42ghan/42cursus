/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:27:47 by ghan              #+#    #+#             */
/*   Updated: 2021/07/06 15:27:48 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_top_two(t_head **head)
{
	t_stack	*top;
	t_stack	*new_top;

	top = (*head)->start->prev;
	new_top = top->prev;
	new_top->prev->next = top;
	top->prev = new_top->prev;
	top->next = new_top;
	new_top->prev = top;
	new_top->next = (*head)->start;
	(*head)->start->prev = new_top;
}

void	push_top(t_head **from, t_head **to)
{
	t_stack	*f_top;
	t_stack	*t_top;

	f_top = (*from)->start->prev;
	t_top = (*to)->start->prev;
	f_top->prev->next = (*from)->start;
	(*from)->start->prev = f_top->prev;
	t_top->next = f_top;
	f_top->prev = t_top;
	f_top->next = (*to)->start;
}

void	rot_n_rev_rot(t_head **head, int direction)
{
	if (!direction)
		(*head)->start = (*head)->start->prev;
	else if (direction == 1)
		(*head)->start = (*head)->start->next;
}
