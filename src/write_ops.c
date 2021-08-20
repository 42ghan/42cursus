/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 19:27:01 by ghan              #+#    #+#             */
/*   Updated: 2021/08/07 19:27:01 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	single_write(int idx, char stack)
{
	if (idx == 1 && stack == 'a')
		write(1, "sa\n", 3);
	else if (idx == 1 && stack == 'b')
		write(1, "sb\n", 3);
	else if (idx == 2 && stack == 'a')
		write(1, "pa\n", 3);
	else if (idx == 2 && stack == 'b')
		write(1, "pb\n", 3);
	else if (idx == 3 && stack == 'a')
		write(1, "ra\n", 3);
	else if (idx == 3 && stack == 'b')
		write(1, "rb\n", 3);
	else if (idx == 4 && stack == 'a')
		write(1, "rra\n", 4);
	else if (idx == 4 && stack == 'b')
		write(1, "rrb\n", 4);
}

void	write_ops(t_ops *ops_lst)
{
	t_ops	*op;

	op = ops_lst;
	while (op)
	{
		if (op->ops_idx != 2 && op->next && op->ops_idx == op->next->ops_idx
			&& op->stack != op->next->stack)
		{
			if (op->ops_idx == 1)
				write(1, "ss\n", 3);
			else if (op->ops_idx == 3)
				write(1, "rr\n", 3);
			else if (op->ops_idx == 4)
				write(1, "rrr\n", 4);
			op = op->next->next;
		}
		else
		{
			single_write(op->ops_idx, op->stack);
			op = op->next;
		}
	}
}
