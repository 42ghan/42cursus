/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:50:09 by ghan              #+#    #+#             */
/*   Updated: 2021/08/02 14:50:10 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	b_to_a(t_head *b_hd, t_head *a_hd, int cnt, int skip)
{
	if (cnt < 2 || cnt_sorted(a_hd, 0, 0) + cnt_sorted(b_hd, skip, 1)
		>= a_hd->t_len - skip)
		return ;
	b_hd->pivot = a_hd->t_len - a_hd->len - cnt / 2;
	while (!check_remainder(b_hd, b_hd->len, 1))
		cnt = b_to_a_push_rot_opt(b_hd, a_hd, cnt);
	if (b_hd->len == 3)
	{
		sort_only_three_b(b_hd);
		cnt -= 3;
	}
	if (skip + cnt_sorted(b_hd, skip, 1) > b_hd->len - cnt)
		cnt -= (skip + cnt_sorted(b_hd, skip, 1)) - (b_hd->len - cnt);
	if (b_hd->len > cnt_sorted(b_hd, skip, 1) + skip)
		b_to_a(b_hd, a_hd, cnt, skip);
}

static void	divide_to_three(t_head *a_hd, t_head *b_hd)
{
	a_hd->pivot = 2 * a_hd->t_len / 3;
	b_hd->pivot = b_hd->t_len / 3;
	while (!check_remainder(a_hd, a_hd->len, 0))
	{
		if (a_hd->start->prev->idx < a_hd->pivot)
		{
			push_top(a_hd, b_hd, 0);
			if (b_hd->start->prev->idx < b_hd->pivot)
				rot_n_rev_rot(b_hd, 0, 1);
		}
		else
			rot_n_rev_rot(a_hd, 0, 0);
	}
}

static void	qsort_sect(t_head *a_hd, t_head *b_hd, int skip, int len)
{
	while (cnt_sorted(a_hd, 0, 0) + cnt_sorted(b_hd, skip, 1) < len)
	{
		qsort_a_to_b(a_hd, b_hd, cnt_sorted(a_hd, 0, 0),
			skip + cnt_sorted(b_hd, skip, 1));
		if (b_hd->len - skip - cnt_sorted(b_hd, skip, 1) > 3)
			b_to_a(b_hd, a_hd, b_hd->len - skip - cnt_sorted(b_hd, skip, 1),
				skip + cnt_sorted(b_hd, skip, 1));
		while (a_hd->len < len - cnt_sorted(b_hd, skip, 1))
		{
			push_top(b_hd, a_hd, 1);
			if (a_hd->len > 1
				&& a_hd->start->prev->idx > a_hd->start->prev->prev->idx
				&& b_hd->len > 1
				&& b_hd->start->prev->idx < b_hd->start->prev->prev->idx)
			{
				swap_top_two(a_hd, 0);
				swap_top_two(b_hd, 1);
			}
			else if (check_three_consecutive(a_hd))
				sort_three_on_top_a(a_hd);
		}
	}
}

static void	more_than_fifty(t_head *a_hd, t_head *b_hd, int t_len)
{
	divide_to_three(a_hd, b_hd);
	qsort_sect(a_hd, b_hd, 2 * t_len / 3, t_len / 3 + t_len % 3);
	b_to_a(b_hd, a_hd, t_len / 3, t_len / 3);
	while (b_hd->len > t_len / 3)
		push_top(b_hd, a_hd, 1);
	qsort_sect(a_hd, b_hd, t_len / 3, 2 * t_len / 3);
	b_to_a(b_hd, a_hd, b_hd->len, 0);
	if (b_hd->len == 3)
		sort_only_three_b(b_hd);
	while (b_hd->len)
		push_top(b_hd, a_hd, 1);
	qsort_sect(a_hd, b_hd, 0, t_len);
	while (b_hd->start)
		push_top(b_hd, a_hd, 1);
}

void	sort_by_len(t_head *a_hd, t_head *b_hd, int t_len)
{
	if (t_len == 2 && !cnt_sorted(a_hd, 0, 0))
		swap_top_two(a_hd, 0);
	else if (t_len == 3 && cnt_sorted(a_hd, 0, 0) < t_len)
		sort_only_three_a(a_hd);
	else if (t_len == 5 && cnt_sorted(a_hd, 0, 0) < t_len)
		sort_five_a(a_hd, b_hd);
	else if (cnt_sorted(a_hd, 0, 0) < t_len)
		more_than_fifty(a_hd, b_hd, t_len);
}
