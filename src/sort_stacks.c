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



void	radix_sort_stacks(t_head **a_head, t_head **b_head, int *hex_cnt)
{
	t_stack				*a_top;
	static unsigned int	rem = 0;

	a_top = (*a_head)->start->prev;
	while ((*a_head)->start)
	{
		if (a_top->u_nbr % 16 == rem)
			push_top(a_head, b_head, 0);
		else
			rot_n_rev_rot(a_head, 0, 0);
		a_top = a_top->prev;
	}
}
