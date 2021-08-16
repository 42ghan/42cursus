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

static void	sort_only_three_b(t_head *b_head)
{
	t_stack	*top;

	top = b_head->start->prev;
	if (top->idx > top->prev->idx && top->idx > b_head->start->idx
	&& b_head->start->idx > top->prev->idx)
	{
		swap_top_two(b_head, 1);
		rot_n_rev_rot(b_head, 1, 0);
	}
	else if (top->idx < top->prev->idx && top->idx > b_head->start->idx)
		swap_top_two(b_head, 1);
	else if (top->idx > top->prev->idx && top->idx < b_head->start->idx)
		rot_n_rev_rot(b_head, 1, 1);
	else if (top->idx < top->prev->idx && top->idx < b_head->start->idx &&
	top->prev->idx > b_head->start->idx)
		rot_n_rev_rot(b_head, 0, 1);
	else if (top->idx < top->prev->idx && top->idx < b_head->start->idx &&
	top->prev->idx < b_head->start->idx)
	{
		swap_top_two(b_head, 1);
		rot_n_rev_rot(b_head, 1, 1);
	}
}

static void	sort_only_three_a(t_head *a_head)
{
	t_stack	*top;


	top = a_head->start->prev;
	if (top->idx < top->prev->idx && top->idx < a_head->start->idx
	&& a_head->start->idx < top->prev->idx)
	{
		swap_top_two(a_head, 0);
		rot_n_rev_rot(a_head, 1, 0);
	}
	else if (top->idx > top->prev->idx && top->idx < a_head->start->idx)
		swap_top_two(a_head, 0);
	else if (top->idx < top->prev->idx && top->idx > a_head->start->idx)
		rot_n_rev_rot(a_head, 1, 0);
	else if (top->idx > top->prev->idx && top->idx > a_head->start->idx &&
	top->prev->idx < a_head->start->idx)
		rot_n_rev_rot(a_head, 0, 0);
	else if (top->idx > top->prev->idx && top->idx > a_head->start->idx &&
	top->prev->idx > a_head->start->idx)
	{
		swap_top_two(a_head, 0);
		rot_n_rev_rot(a_head, 1, 0);
	}
}

static void	sort_three_on_top_b(t_head *b_head)
{
	t_stack	*top;

	if (b_head->len < 4)
		return ;
	top = b_head->start->prev;
	if (top->idx > top->prev->idx && top->idx > top->prev->prev->idx
	&& top->prev->prev->idx > top->prev->idx)
	{
		rot_n_rev_rot(b_head, 0, 1);
		swap_top_two(b_head, 1);
		rot_n_rev_rot(b_head, 1, 1);
	}
	else if (top->idx < top->prev->idx && top->idx > top->prev->prev->idx)
		swap_top_two(b_head, 1);
	else if (top->idx > top->prev->idx && top->idx < top->prev->prev->idx)
	{
		rot_n_rev_rot(b_head, 0, 1);
		swap_top_two(b_head, 1);
		rot_n_rev_rot(b_head, 1, 1);
		swap_top_two(b_head, 1);
	}
	else if (top->idx < top->prev->idx && top->idx < top->prev->prev->idx)
	{
		swap_top_two(b_head, 1);
		sort_three_on_top_b(b_head);
	}
}

static void	sort_three_on_top_a(t_head *a_head)
{
	t_stack	*top;

	if (a_head->len < 4)
		return ;
	top = a_head->start->prev;
	if (top->idx < top->prev->idx && top->idx < top->prev->prev->idx
	&& top->prev->prev->idx < top->prev->idx)
	{
		rot_n_rev_rot(a_head, 0, 0);
		swap_top_two(a_head, 0);
		rot_n_rev_rot(a_head, 1, 0);
	}
	else if (top->idx > top->prev->idx && top->idx < top->prev->prev->idx)
		swap_top_two(a_head, 0);
	else if (top->idx < top->prev->idx && top->idx > top->prev->prev->idx)
	{
		rot_n_rev_rot(a_head, 0, 0);
		swap_top_two(a_head, 0);
		rot_n_rev_rot(a_head, 1, 0);
		swap_top_two(a_head, 0);
	}
	else if (top->idx > top->prev->idx && top->idx > top->prev->prev->idx)
	{
		swap_top_two(a_head, 0);
		sort_three_on_top_a(a_head);
	}
}

static int	cnt_sorted(t_head *head, int skip, int flag)
{
	t_stack	*cur;
	int		n;
	int		i;

	cur = head->start;
	n = head->total_len;
	if (flag)
		n = 1;
	i = 0;
	while (i < skip)
	{
		cur = cur->next;
		i++;
		if (flag)
			n++;
	}
	i = 0;
	while (i + skip < head->len)
	{
		if (cur->idx != n)
			return (i);
		cur = cur->next;
		i++;
		if (!flag)
			n--;
		else
			n++;
	}
	return (i);
}

static int	check_remainder(t_head *head, int len, int flag)
{
	t_stack	*cur;
	int		i;

	if (head->len < 2)
		return (1);
	i = 0;
	cur = head->start->prev;
	while (i < len)
	{
		if ((!flag && cur->idx < head->pivot) ||
		(flag && cur->idx > head->pivot))
			return (0);
		cur = cur->prev;
		i++;
	}
	return (1);
}

int	push_optimize_position(t_head *from, t_head *to, int pivot, int flag)
{
	int	rot_cnt;

	rot_cnt = 0;
	push_top(from, to, flag);
	if (to->len > 2)
	{
		if ((!flag && to->start->prev->idx < pivot) ||
		(flag && to->start->prev->idx > pivot))
		{
			rot_n_rev_rot(to, 0, !flag);
			rot_cnt = 1;
		}
	}
	return (rot_cnt);
}

static int	determine_optimal_direction(t_head *head, int flag)
{
	int		i;
	t_stack	*cur;

	cur = head->start->prev;
	i = 0;
	while (i < head->len)
	{
		if ((!flag && cur->idx < head->pivot) || (flag && cur->idx > head->pivot))
			break ;
		cur = cur->prev;
		i++;
	}
	if (!i)
		return (-1);
	else if (i <= head->len / 2)
		return (0);
	return (1);
}

void	qsort_large_b_to_a(t_head *b_head, t_head *a_head, int cnt, int section)
{
	int	rot_cnt;

	if (cnt_sorted(a_head, 0, 0) + cnt_sorted(b_head, section, 1) == a_head->total_len - section)
		return ;
	rot_cnt = 0;
	b_head->pivot = a_head->total_len - a_head->len - cnt / 2;
	while (!check_remainder(b_head, b_head->len, 1))
	{
		if (b_head->start->prev->idx > b_head->pivot)
		{
			push_top(b_head, a_head, 1);
			if (a_head->len > 1 && a_head->start->prev->idx > a_head->start->prev->prev->idx)
				swap_top_two(a_head, 0);
			if (b_head->len > 1 && b_head->start->prev->idx < b_head->start->prev->prev->idx)
				swap_top_two(b_head, 1);
			if (a_head->len > 3)
			{
				int sum = a_head->start->prev->idx + a_head->start->prev->prev->idx + a_head->start->prev->prev->prev->idx;
				if ((a_head->start->prev->idx - sum >= -1 && a_head->start->prev->idx - sum <= 1) && (sum / 3 == a_head->start->prev->idx || sum / 3 == a_head->start->prev->prev->idx || sum / 3 == a_head->start->prev->prev->idx))
					sort_three_on_top_a(a_head);
			}
			(cnt)--;
		}
		else
		{
			rot_n_rev_rot(b_head, 0, 1);
			rot_cnt++;
		}
	}
	while (--rot_cnt >= 0)
	{
		rot_n_rev_rot(b_head, 1, 1);
		if (a_head->len > 1 && a_head->start->prev->idx > a_head->start->prev->prev->idx)
			swap_top_two(a_head, 0);
		if (b_head->len > 1 && b_head->start->prev->idx < b_head->start->prev->prev->idx)
			swap_top_two(b_head, 1);
		if (b_head->len > 3)
		{
			int sum = b_head->start->prev->idx + b_head->start->prev->prev->idx + b_head->start->prev->prev->prev->idx;
			if ((b_head->start->prev->idx - sum >= -1 && b_head->start->prev->idx - sum <= 1) && (sum / 3 == b_head->start->prev->idx || sum / 3 == b_head->start->prev->prev->idx || sum / 3 == b_head->start->prev->prev->idx))
				sort_three_on_top_b(b_head);
		}
		if (b_head->len && a_head->start->prev->idx - b_head->start->prev->idx == 1)
		{
			push_top(b_head, a_head, 1);
			cnt--;
		}
	}
	if (cnt > 1)
		qsort_large_b_to_a(b_head, a_head, cnt, section);
}

void	qsort_large(t_head *a_head, t_head *b_head, int cnt_s, int section)
{
	int	push_cnt;
	int	rot_cnt;

	if (a_head->len < 3 || cnt_sorted(a_head, 0, 0) + cnt_sorted(b_head, section, 1) == a_head->total_len - section)
		return ;
	push_cnt = 0;
	rot_cnt = 0;
	a_head->pivot = a_head->total_len - cnt_s - (a_head->len - cnt_s) / 2;
	while (!check_remainder(a_head, a_head->len, 0) && a_head->len > 3)
	{
		if (a_head->start->prev->idx < a_head->pivot)
		{
			push_top(a_head, b_head, 0);
			if (b_head->len > 1 && b_head->start->prev->idx < b_head->start->prev->prev->idx)
				swap_top_two(b_head, 1);
			if (a_head->len > 1 && a_head->start->prev->idx > a_head->start->prev->prev->idx)
				swap_top_two(a_head, 0);
			if (b_head->len > 3)
			{
				int sum = b_head->start->prev->idx + b_head->start->prev->prev->idx + b_head->start->prev->prev->prev->idx;
				if ((b_head->start->prev->idx - sum >= -1 && b_head->start->prev->idx - sum <= 1) && (sum / 3 == b_head->start->prev->idx || sum / 3 == b_head->start->prev->prev->idx || sum / 3 == b_head->start->prev->prev->idx))
					sort_three_on_top_b(b_head);
			}
			push_cnt++;
		}
		else
		{
			rot_n_rev_rot(a_head, 0, 0);
			if (cnt_s)
				rot_cnt++;
		}
	}
	while (--rot_cnt >= 0)
	{
		rot_n_rev_rot(a_head, 1, 0);
		if (a_head->len > 1 && a_head->start->prev->idx > a_head->start->prev->prev->idx)
			swap_top_two(a_head, 0);
		if (b_head->len > 1 && b_head->start->prev->idx < b_head->start->prev->prev->idx)
			swap_top_two(b_head, 1);
		if (a_head->len > 3)
		{
			int sum = a_head->start->prev->idx + a_head->start->prev->prev->idx + a_head->start->prev->prev->prev->idx;
			if ((a_head->start->prev->idx - sum >= -1 && a_head->start->prev->idx - sum <= 1) && (sum / 3 == a_head->start->prev->idx || sum / 3 == a_head->start->prev->prev->idx || sum / 3 == a_head->start->prev->prev->idx))
				sort_three_on_top_a(a_head);
		}
	}
	if (a_head->len == 3)
		sort_only_three_a(a_head);
	if (a_head->len > cnt_sorted(a_head, 0, 0))
		qsort_large(a_head, b_head, cnt_sorted(a_head, 0, 0), section);
	qsort_large_b_to_a(b_head, a_head, push_cnt, section);
}

void	b_to_a(t_head *b_head, t_head *a_head, int cnt, int section)
{
	int	rot_cnt;

	rot_cnt = 0;
	if (cnt < 2 || cnt_sorted(a_head, 0, 0) + cnt_sorted(b_head, section, 0) == a_head->total_len - section)
		return ;
	b_head->pivot = a_head->total_len - a_head->len - cnt / 2;
	while (!check_remainder(b_head, b_head->len, 1))
	{
		if (b_head->start->prev->idx > b_head->pivot)
		{
			push_top(b_head, a_head, 1);
			if (b_head->len > 1 && b_head->start->prev->idx < b_head->start->prev->prev->idx)
				swap_top_two(b_head, 1);
			if (a_head->len > 1 && a_head->start->prev->idx > a_head->start->prev->prev->idx)
				swap_top_two(a_head, 0);
			cnt--;
		}
		else
		{
			rot_n_rev_rot(b_head, 0, 1);
			rot_cnt++;
		}
	}
	while ((b_head->len > a_head->total_len / 3 || cnt_sorted(b_head, rot_cnt + section, 1)) && --rot_cnt >= 0)
		rot_n_rev_rot(b_head, 1, 1);
	if (b_head->len > 3)
		b_to_a(b_head, a_head, cnt - cnt_sorted(b_head, section, 1), section);
}

static void	divide_to_three(t_head *a_head, t_head *b_head)
{
	a_head->pivot = 2 * a_head->total_len / 3;
	b_head->pivot = b_head->total_len / 3;
	while (!check_remainder(a_head, a_head->len, 0))
	{
		if (a_head->start->prev->idx < a_head->pivot)
		{
			push_top(a_head, b_head, 0);
			if (b_head->start->prev->idx < b_head->pivot)
				rot_n_rev_rot(b_head, 0, 1);
		}
		else
			rot_n_rev_rot(a_head, 0, 0);
	}
}

static void	divide_to_five(t_head *a_head, t_head *b_head)
{
	a_head->pivot = a_head->total_len / 2;
	b_head->pivot = a_head->total_len / 4;
	while (!check_remainder(a_head, a_head->len, 0))
	{
		if (a_head->start->prev->idx < a_head->pivot)
			push_top(a_head, b_head, 0);
			if (b_head->start->prev->idx < b_head->pivot)
				rot_n_rev_rot(b_head, 0, 1);
		else
			rot_n_rev_rot(a_head, 0, 0);
	}
	a_head->pivot = a_head->total_len - a_head->total_len / 4;
		while (!check_remainder(a_head, a_head->len, 0))
	{
		if (a_head->start->prev->idx < a_head->pivot)
			push_top(a_head, b_head, 0);
		else
			rot_n_rev_rot(a_head, 0, 0);
	}
}

void	sort_stacks(t_head *a_head, t_head *b_head)
{
	divide_to_three(a_head, b_head);
	while (cnt_sorted(a_head, 0, 0) + cnt_sorted(b_head, 2 * a_head->total_len / 3, 1) < a_head->total_len / 3 + a_head->total_len % 3)
	{
		qsort_large(a_head, b_head, cnt_sorted(a_head, 0, 0), 2 * a_head->total_len / 3);
		b_to_a(b_head, a_head, b_head->len - cnt_sorted(b_head, 2 * a_head->total_len / 3, 1) - 2 * a_head->total_len / 3, 2 * a_head->total_len / 3);
		while (a_head->len < a_head->total_len / 3 + a_head->total_len % 3 - cnt_sorted(b_head, 2 * a_head->total_len / 3, 1))
		{
			push_top(b_head, a_head, 1);
			if (b_head->len > 1 && b_head->start->prev->idx < b_head->start->prev->prev->idx)
				swap_top_two(b_head, 1);
			if (a_head->start->prev->idx > a_head->start->prev->prev->idx)
				swap_top_two(a_head, 0);
		}
	}
	while (a_head->len < a_head->total_len / 3 + a_head->total_len % 3)
		push_top(b_head, a_head, 1);
	b_to_a(b_head, a_head, a_head->total_len / 3, a_head->total_len / 3);
	while (b_head->len > a_head->total_len / 3)
		push_top(b_head, a_head, 1);
	while (cnt_sorted(a_head, 0, 0) + cnt_sorted(b_head, a_head->total_len / 3, 1) < 2 * a_head->total_len / 3)
	{
		qsort_large(a_head, b_head, cnt_sorted(a_head, 0, 0), a_head->total_len / 3);
		b_to_a(b_head, a_head, b_head->len - cnt_sorted(b_head, a_head->total_len / 3, 1) - a_head->total_len / 3, a_head->total_len / 3);
		while (a_head->len < 2 * a_head->total_len / 3 + a_head->total_len % 3 - cnt_sorted(b_head, a_head->total_len / 3, 1))
		{
			push_top(b_head, a_head, 1);
			if (b_head->len > 1 && b_head->start->prev->idx < b_head->start->prev->prev->idx)
				swap_top_two(b_head, 1);
			if (a_head->start->prev->idx > a_head->start->prev->prev->idx)
				swap_top_two(a_head, 0);
		}
	}
	while (b_head->len > a_head->total_len / 3)
		push_top(b_head, a_head, 1);
	b_to_a(b_head, a_head, a_head->total_len / 3, 0);
	sort_only_three_b(b_head);
	while (b_head->start)
		push_top(b_head, a_head, 1);
	while (cnt_sorted(a_head, 0, 0) + cnt_sorted(b_head, 0, 1) < a_head->total_len)
	{
		qsort_large(a_head, b_head, cnt_sorted(a_head, 0, 0), 0);
		b_to_a(b_head, a_head, b_head->len - cnt_sorted(b_head, 0, 1), 0);
		while (a_head->len < a_head->total_len - cnt_sorted(b_head, 0, 1))
		{
			push_top(b_head, a_head, 1);
			if (b_head->len > 1 && b_head->start->prev->idx < b_head->start->prev->prev->idx)
				swap_top_two(b_head, 1);
			if (a_head->start->prev->idx > a_head->start->prev->prev->idx)
				swap_top_two(a_head, 0);
		}
	}
	while (b_head->start)
		push_top(b_head, a_head, 1);
}
