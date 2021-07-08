/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:08:08 by ghan              #+#    #+#             */
/*   Updated: 2021/07/07 17:08:09 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		check_sorted(t_head **head, int key, int flag)
{
	t_stack	*cur;

	cur = (*head)->start->prev;
	if (cur->nbr != key)
		return (0);
	while (cur != (*head)->start)
	{
		if (flag == 0 && cur->nbr > cur->prev->nbr)
			return (0);
		if (flag == 1 && cur->nbr < cur->prev->nbr)
			return (0);
		cur = cur->prev;
	}
	return (1);
}

// int	determine_pos(t_head **head, int flag)
// {
// 	t_stack	*top;
// 	t_stack *cmp;
// 	int		pos;

// 	top = (*head)->start->prev;
// 	cmp = (*head)->start;
// 	pos = 0;
// 	if (!flag)
// 	{
// 		while (top->nbr < cmp->nbr)
// 		{
// 			pos++;
// 			cmp = cmp->next;
// 		}
// 	}
// 	else
// 	{
// 		while (top->nbr > cmp->nbr)
// 		{
// 			pos++;
// 			cmp = cmp->next;
// 		}
// 	}
// 	return (pos);
// }

void	move_small(t_head **a_head, t_head **b_head)
{
	int	len;
	int	i;

	len = (*b_head)->len;
	i = 0;
	while (i < len)
	{
		push_top(b_head, a_head);
		i++;
	}
}

void	qsort_stack_mid(t_head **a_head, t_head **b_head, int key)
{
	t_stack	*cur;
	int		min;

	min = key;
	while (!check_sorted(b_head, key, 1))
	{	
		cur = (*b_head)->start->prev;
		if (cur->nbr > key)
		{
			if (cur->prev->nbr > key && cur->prev->prev->nbr > cur->prev->nbr)
				swap_top_two(a_head);
			push_top(b_head, a_head);
			if ((*a_head)->start->prev->nbr > (*a_head)->start->prev->prev->nbr)
				swap_top_two(a_head);
		}
		else if (cur->nbr < key)
		{
			if (cur->nbr > min)
			{
				rot_n_rev_rot(a_head, 1);
				swap_top_two(a_head);
				rot_n_rev_rot(b_head, 0);
			}
			else
				min = cur->nbr;
			rot_n_rev_rot(b_head, 0);
		}
		else if (cur->nbr == key)
			swap_top_two(b_head);
	}
}

void	qsort_stack_large(t_head **a_head, t_head **b_head, int key)
{
	t_stack	*cur;
	int		max;

	max = key;
	while (!check_sorted(a_head, key, 0))
	{	
		cur = (*a_head)->start->prev;
		if (cur->nbr < key)
			push_top(a_head, b_head);
		else if (cur->nbr > key)
		{
			if (cur->nbr < max)
			{
				rot_n_rev_rot(a_head, 1);
				swap_top_two(a_head);
				rot_n_rev_rot(a_head, 0);
			}
			else
				max = cur->nbr;
			rot_n_rev_rot(a_head, 0);
		}
		else if (cur->nbr == key)
			swap_top_two(a_head);
	}
}
