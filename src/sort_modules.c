/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_modules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 00:50:33 by ghan              #+#    #+#             */
/*   Updated: 2021/08/19 01:57:59 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	qsort_a_to_b(t_head *a_hd, t_head *b_hd, int cnt_s, int skip);

int	b_to_a_push_rot_opt(t_head *b_hd, t_head *a_hd, int cnt, int flag)
{
	if (cnt == 2 && b_hd->start->prev->idx < b_hd->start->prev->prev->idx)
		swap_top_two(b_hd, 1);
	if (b_hd->start->prev->idx > b_hd->pivot)
	{
		push_top(b_hd, a_hd, 1);
		if (a_hd->len > 1 && !flag
			&& a_hd->start->prev->idx > a_hd->start->prev->prev->idx)
			swap_top_two(a_hd, 0);
		if (b_hd->len > 1 && !flag
			&& b_hd->start->prev->idx < b_hd->start->prev->prev->idx)
			swap_top_two(b_hd, 1);
		if (check_three_consecutive(a_hd))
			sort_three_on_top_a(a_hd);
		if (flag && b_hd->len > 1 && a_hd->len > 1
			&& b_hd->start->prev->idx < b_hd->start->prev->prev->idx
			&& a_hd->start->prev->idx > a_hd->start->prev->prev->idx)
		{
			swap_top_two(b_hd, 1);
			swap_top_two(a_hd, 0);
		}
		cnt--;
	}
	else
		rot_n_rev_rot(b_hd, determine_optimal_direction(b_hd, 1), 1);
	return (cnt);
}

static int	a_to_b_push_optimize(t_head *a_hd, t_head *b_hd)
{
	push_top(a_hd, b_hd, 0);
	if (a_hd->len > 1 && a_hd->start->prev->idx
		> a_hd->start->prev->prev->idx)
	{
		swap_top_two(a_hd, 0);
		if (b_hd->len > 1 && b_hd->start->prev->idx
			< b_hd->start->prev->prev->idx)
			swap_top_two(b_hd, 1);
	}
	if (check_three_consecutive(b_hd))
		sort_three_on_top_b(b_hd);
	return (1);
}

static void	a_to_b_after_push(t_head *a_hd, t_head *b_hd, int cnt_s, int r_cnt)
{
	while (--r_cnt >= 0 && cnt_s)
	{
		rot_n_rev_rot(a_hd, 1, 0);
		if (b_hd->start->idx > b_hd->pivot)
			rot_n_rev_rot(b_hd, 1, 1);
	}
	if (a_hd->len == 3)
		sort_only_three_a(a_hd);
	else if (a_hd->len == cnt_sorted(a_hd, 0, 0) + 3
		&& check_three_consecutive(a_hd))
		sort_three_on_top_a(a_hd);
}

static void	qsort_b_to_a(t_head *b_hd, t_head *a_hd, int cnt, int skip)
{
	if (cnt_sorted(a_hd, 0, 0) + cnt_sorted(b_hd, skip, 1)
		>= a_hd->t_len - skip)
		return ;
	b_hd->pivot = a_hd->t_len - a_hd->len - cnt / 2;
	while (!check_remainder(b_hd, b_hd->len, 1))
		cnt = b_to_a_push_rot_opt(b_hd, a_hd, cnt, 0);
	if (b_hd->len == cnt_sorted(b_hd, skip, 1) + 3 + skip
		&& check_three_consecutive(b_hd))
	{
		sort_three_on_top_b(b_hd);
		cnt -= 3;
	}
	if (skip + cnt_sorted(b_hd, skip, 1) > b_hd->len - cnt)
		cnt -= (skip + cnt_sorted(b_hd, skip, 1)) - (b_hd->len - cnt);
	if (cnt > 1)
	{
		qsort_a_to_b(a_hd, b_hd, cnt_sorted(a_hd, 0, 0), skip);
		qsort_b_to_a(b_hd, a_hd, cnt, skip);
	}
	if (cnt == 1)
	{
		if (b_hd->len > 2 && b_hd->start->idx > b_hd->start->prev->idx)
			rot_n_rev_rot(b_hd, 1, 1);
		push_top(b_hd, a_hd, 1);
	}
}

void	qsort_a_to_b(t_head *a_hd, t_head *b_hd, int cnt_s, int skip)
{
	int	push_cnt;
	int	rot_cnt;

	push_cnt = 0;
	rot_cnt = 0;
	if (a_hd->len < 3 || cnt_sorted(a_hd, 0, 0) + cnt_sorted(b_hd, skip, 1)
		>= a_hd->t_len - skip)
		return ;
	a_hd->pivot = a_hd->t_len - cnt_s - (a_hd->len - cnt_s) / 2;
	while (!check_remainder(a_hd, a_hd->len, 0)
		&& a_hd->len > cnt_sorted(a_hd, rot_cnt, 0))
	{
		if (cnt_sorted(a_hd, rot_cnt, 0) + cnt_sorted(b_hd, skip, 1)
			>= a_hd->t_len - skip)
			return ;
		if (a_hd->start->prev->idx < a_hd->pivot)
			push_cnt += a_to_b_push_optimize(a_hd, b_hd);
		else
			rot_cnt += rot_n_rev_rot(a_hd, 0, 0);
	}
	b_hd->pivot = a_hd->t_len - a_hd->len - push_cnt / 2;
	a_to_b_after_push(a_hd, b_hd, cnt_s, rot_cnt);
	if (a_hd->len > cnt_sorted(a_hd, 0, 0))
		qsort_a_to_b(a_hd, b_hd, cnt_sorted(a_hd, 0, 0), skip);
	qsort_b_to_a(b_hd, a_hd, push_cnt, skip);
}
