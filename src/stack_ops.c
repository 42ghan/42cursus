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

static void	ops_lstnew_addback(t_head *head, int idx, char stack)
{
	t_ops	*new;
	t_ops	*elem;

	new = (t_ops *)ft_calloc(1, sizeof(t_ops));
	if (!new)
		error_exit(2);
	new->ops_idx = idx;
	new->stack = stack;
	elem = *(head->ops);
	while (elem->next != NULL)
		elem = elem->next;
	elem->next = new;
	new->next = NULL;
}

void	swap_top_two(t_head *head, int flag)
{
	t_stack	*top;
	t_stack	*new_top;

	if (head->len < 2)
		return ;
	if (head->len == 2)
	{
		head->start = head->start->prev;
		return ;
	}
	top = head->start->prev;
	new_top = top->prev;
	new_top->prev->next = top;
	top->prev = new_top->prev;
	top->next = new_top;
	new_top->prev = top;
	new_top->next = head->start;
	head->start->prev = new_top;
	if (flag == 0)
		ops_lstnew_addback(head, 1, 'a');
	else if (flag == 1)
		ops_lstnew_addback(head, 1, 'b');
}

void	push_top(t_head *from, t_head *to, int flag)
{
	t_stack	*f_top;
	t_stack	*t_top;

	if (from->start == NULL)
		return ;
	f_top = from->start->prev;
	f_top->prev->next = from->start;
	from->start->prev = f_top->prev;
	if (to->start == NULL)
	{
		to->start = f_top;
		to->start->prev = to->start;
		to->start->next = to->start;
	}
	else
		elem_to_top(to, f_top);
	if (from->len == 1)
		from->start = NULL;
	(from->len)--;
	(to->len)++;
	if (flag == 0)
		ops_lstnew_addback(from, 2, 'b');
	else if (flag == 1)
		ops_lstnew_addback(from, 2, 'a');
}

int	rot_n_rev_rot(t_head *head, int direction, int flag)
{
	if (head->len < 2 || direction == -1)
		return (-1);
	if (!direction)
	{
		head->start = head->start->prev;
		if (flag == 0)
			ops_lstnew_addback(head, 3, 'a');
		else if (flag == 1)
			ops_lstnew_addback(head, 3, 'b');
	}
	else if (direction == 1)
	{
		head->start = head->start->next;
		if (flag == 0)
			ops_lstnew_addback(head, 4, 'a');
		else if (flag == 1)
			ops_lstnew_addback(head, 4, 'b');
	}
	if (!flag)
		return (1);
	return (0);
}
