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

void	write_ops(t_ops *ops_lst)
{
	t_ops	*op;

	op = ops_lst->next;
	while (op->next != NULL && op)
	{
		if (op->next && op->ops_idx == op->next->ops_idx && op->stack != op->next->stack)
		{
			if (op->ops_idx == 1)
				write(1, "ss\n", 4);
			else if (op->ops_idx == 3)
				write(1, "rr\n", 4);
			else if (op->ops_idx == 4)
				write(1, "rrr\n", 4);
			op = op->next->next;
		}
		else
		{
			if (op->ops_idx == 1 && op->stack == 'a')
				write(1, "sa\n", 4);
			else if (op->ops_idx == 1 && op->stack == 'b')
				write(1, "sb\n", 4);
			else if (op->ops_idx == 2 && op->stack == 'a')
				write(1, "pa\n", 4);
			else if (op->ops_idx == 2 && op->stack == 'b')
				write(1, "pb\n", 4);
			else if (op->ops_idx == 3 && op->stack == 'a')
				write(1, "ra\n", 4);
			else if (op->ops_idx == 3 && op->stack == 'b')
				write(1, "rb\n", 4);
			else if (op->ops_idx == 4 && op->stack == 'a')
				write(1, "rra\n", 4);
			else if (op->ops_idx == 4 && op->stack == 'b')
				write(1, "rrb\n", 4);
			op = op->next;
		}
	}
}
