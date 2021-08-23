/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:38:07 by ghan              #+#    #+#             */
/*   Updated: 2021/08/18 23:38:20 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cnt_sorted(t_head *head, int skip, int flag)
{
	t_stack	*cur;
	int		i;

	cur = head->start;
	if (!cur)
		return (0);
	i = -1;
	while (++i < skip)
		cur = cur->next;
	i = -1;
	while (++i + skip < head->len)
	{
		if ((!flag && cur->idx != head->t_len - i)
			|| (flag && cur->idx != i + 1))
			return (i);
		cur = cur->next;
	}
	return (i);
}

int	check_remainder(t_head *head, int len, int flag)
{
	t_stack	*cur;
	int		i;

	if (head->len < 1)
		return (1);
	i = 0;
	cur = head->start->prev;
	while (i < len)
	{
		if ((!flag && cur->idx < head->pivot)
			|| (flag && cur->idx > head->pivot))
			return (0);
		cur = cur->prev;
		i++;
	}
	return (1);
}

int	determine_optimal_direction(t_head *head, int flag)
{
	int		i;
	t_stack	*cur;

	if (head->start == NULL)
		return (-1);
	cur = head->start->prev;
	i = 0;
	while (i < head->len)
	{
		if ((!flag && cur->idx < head->pivot)
			|| (flag && cur->idx > head->pivot))
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

int	check_three_consecutive(t_head *head)
{
	t_stack	*top;
	int		avrg;

	if (head->len < 4)
		return (0);
	top = head->start->prev;
	avrg = (top->idx + top->prev->idx + top->prev->prev->idx) / 3;
	if ((top->idx - avrg >= -1 && top->idx - avrg <= 1)
		&& (avrg == top->idx || avrg == top->prev->idx
			|| avrg == top->prev->prev->idx))
		return (1);
	return (0);
}
