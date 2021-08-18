/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:07:54 by ghan              #+#    #+#             */
/*   Updated: 2021/08/18 23:07:56 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_only_three_b(t_head *b_hd)
{
	t_stack	*top;

	top = b_hd->start->prev;
	if (top->idx > top->prev->idx && top->idx > b_hd->start->idx
		&& b_hd->start->idx > top->prev->idx)
	{
		swap_top_two(b_hd, 1);
		rot_n_rev_rot(b_hd, 1, 1);
	}
	else if (top->idx < top->prev->idx && top->idx > b_hd->start->idx)
		swap_top_two(b_hd, 1);
	else if (top->idx > top->prev->idx && top->idx < b_hd->start->idx)
		rot_n_rev_rot(b_hd, 1, 1);
	else if (top->idx < top->prev->idx && top->idx < b_hd->start->idx
		&& top->prev->idx > b_hd->start->idx)
		rot_n_rev_rot(b_hd, 0, 1);
	else if (top->idx < top->prev->idx && top->idx < b_hd->start->idx
		&& top->prev->idx < b_hd->start->idx)
	{
		swap_top_two(b_hd, 1);
		rot_n_rev_rot(b_hd, 1, 1);
	}
}

void	sort_only_three_a(t_head *a_hd)
{
	t_stack	*top;

	top = a_hd->start->prev;
	if (top->idx < top->prev->idx && top->idx < a_hd->start->idx
		&& a_hd->start->idx < top->prev->idx)
	{
		swap_top_two(a_hd, 0);
		rot_n_rev_rot(a_hd, 1, 0);
	}
	else if (top->idx > top->prev->idx && top->idx < a_hd->start->idx)
		swap_top_two(a_hd, 0);
	else if (top->idx < top->prev->idx && top->idx > a_hd->start->idx)
		rot_n_rev_rot(a_hd, 1, 0);
	else if (top->idx > top->prev->idx && top->idx > a_hd->start->idx
		&& top->prev->idx < a_hd->start->idx)
		rot_n_rev_rot(a_hd, 0, 0);
	else if (top->idx > top->prev->idx && top->idx > a_hd->start->idx
		&& top->prev->idx > a_hd->start->idx)
	{
		swap_top_two(a_hd, 0);
		rot_n_rev_rot(a_hd, 1, 0);
	}
}

void	sort_three_on_top_b(t_head *b_hd)
{
	t_stack	*top;

	top = b_hd->start->prev;
	if (top->idx > top->prev->idx && top->idx > top->prev->prev->idx
		&& top->prev->prev->idx > top->prev->idx)
	{
		rot_n_rev_rot(b_hd, 0, 1);
		swap_top_two(b_hd, 1);
		rot_n_rev_rot(b_hd, 1, 1);
	}
	else if (top->idx < top->prev->idx && top->idx > top->prev->prev->idx)
		swap_top_two(b_hd, 1);
	else if (top->idx > top->prev->idx && top->idx < top->prev->prev->idx)
	{
		rot_n_rev_rot(b_hd, 0, 1);
		swap_top_two(b_hd, 1);
		rot_n_rev_rot(b_hd, 1, 1);
		swap_top_two(b_hd, 1);
	}
	else if (top->idx < top->prev->idx && top->idx < top->prev->prev->idx)
	{
		swap_top_two(b_hd, 1);
		sort_three_on_top_b(b_hd);
	}
}

void	sort_three_on_top_a(t_head *a_hd)
{
	t_stack	*top;

	top = a_hd->start->prev;
	if (top->idx < top->prev->idx && top->idx < top->prev->prev->idx
		&& top->prev->prev->idx < top->prev->idx)
	{
		rot_n_rev_rot(a_hd, 0, 0);
		swap_top_two(a_hd, 0);
		rot_n_rev_rot(a_hd, 1, 0);
	}
	else if (top->idx > top->prev->idx && top->idx < top->prev->prev->idx)
		swap_top_two(a_hd, 0);
	else if (top->idx < top->prev->idx && top->idx > top->prev->prev->idx)
	{
		rot_n_rev_rot(a_hd, 0, 0);
		swap_top_two(a_hd, 0);
		rot_n_rev_rot(a_hd, 1, 0);
		swap_top_two(a_hd, 0);
	}
	else if (top->idx > top->prev->idx && top->idx > top->prev->prev->idx)
	{
		swap_top_two(a_hd, 0);
		sort_three_on_top_a(a_hd);
	}
}
