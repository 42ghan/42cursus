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

void	swap_top_two(t_head **head, int flag)
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
	if (flag == 0)
		write(1, "sa\n", 4);
	else if (flag == 1)
		write(1, "sb\n", 4);
}

void	push_top(t_head **from, t_head **to, int flag)
{
	t_stack	*f_top;
	t_stack	*t_top;

	if ((*from)->start == NULL)
		return ;
	f_top = (*from)->start->prev;
	f_top->prev->next = (*from)->start;
	(*from)->start->prev = f_top->prev;
	if ((*to)->start == NULL)
	{
		(*to)->start = f_top;
		(*to)->start->prev = (*to)->start;
		(*to)->start->next = (*to)->start;
	}
	else
		elem_to_top(to, f_top);
	if ((*from)->len == 1)
		(*from)->start = NULL;
	((*from)->len)--;
	((*to)->len)++;
	if (flag == 0)
		write(1, "pb\n", 4);
	else if (flag == 1)
		write(1, "pa\n", 4);
}

void	rot_n_rev_rot(t_head **head, int direction, int flag)
{
	if (!direction)
	{
		(*head)->start = (*head)->start->prev;
		if (flag == 0)
			write(1, "ra\n", 4);
		else if (flag == 1)
			write(1, "rb\n", 4);
	}
	else if (direction == 1)
	{
		(*head)->start = (*head)->start->next;
		if (flag == 0)
			write(1, "rra\n", 4);
		else if (flag == 1)
			write(1, "rrb\n", 4);
	}
}
