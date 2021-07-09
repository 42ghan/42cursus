/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:10:02 by ghan              #+#    #+#             */
/*   Updated: 2021/07/08 18:10:03 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

static int	check_remaining_digit(t_head **head, int pos, int digit)
{
	t_stack	*cur;
	int		i;

	if ((*head)->start == NULL)
		return (0);
	cur = (*head)->start->prev;
	i = 0;
	while (i < (*head)->len)
	{
		if (cur->u_str[pos] == "0123456789"[digit])
			return (1);
		cur = cur->prev;
		i++;
	}
	return (0);
}

void	radix_sort_stacks(t_head **a_head, t_head **b_head)
{
	t_stack	*a_top;
	t_stack	*b_top;
	int		digit;
	int		pos;
	int		rot_cnt;

	pos = 9;
	while (pos >= 0)
	{
		rot_cnt = 0;
		digit = 0;
		while ((*a_head)->start && (digit < 10) && (pos % 2 == 1))
		{
			if (!check_remaining_digit(a_head, pos, digit))
			{
				digit++;
				while (rot_cnt > 0)
				{
					rot_n_rev_rot(a_head, 1, 0);
					rot_cnt--;
				}
			}
			a_top = (*a_head)->start->prev;
			if (a_top->u_str[pos] == "0123456789"[digit])
				push_top(a_head, b_head, 0);
			else
			{
				rot_n_rev_rot(a_head, 0, 0);
				rot_cnt++;
			}
		}
		digit = 9;
		while ((*b_head)->start && (digit >= 0) && !(pos % 2))
		{
			if (!check_remaining_digit(b_head, pos, digit))
			{
				digit--;
				while (rot_cnt > 0)
				{
					rot_n_rev_rot(b_head, 1, 1);
					rot_cnt--;
				}
			}
			b_top = (*b_head)->start->prev;
			if (b_top->u_str[pos] == "0123456789"[digit])
				push_top(b_head, a_head, 1);
			else
			{
				rot_n_rev_rot(b_head, 0, 1);
				rot_cnt++;
			}
		}
		pos--;
	}
}
