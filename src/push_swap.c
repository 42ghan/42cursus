/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:09:18 by ghan              #+#    #+#             */
/*   Updated: 2021/08/19 01:57:35 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_alloc(t_head *a_hd, t_ops **ops_lst)
{
	t_stack	*cur;
	t_ops	*cur_op;

	while (a_hd->len)
	{
		cur = a_hd->start;
		a_hd->start = a_hd->start->next;
		free(cur);
		(a_hd->len)--;
		cur = NULL;
	}
	cur_op = (*ops_lst)->next;
	while (cur_op)
	{
		free(*ops_lst);
		*ops_lst = cur_op;
		cur_op = cur_op->next;
	}
	free(*ops_lst);
}

void	put_in_order(t_head *a_hd, int *sorted)
{
	t_stack	*cur;
	int		i;
	int		k;

	i = 0;
	while (i < a_hd->len)
	{
		cur = a_hd->start;
		k = 0;
		while (k < a_hd->len)
		{
			if (cur->nbr == sorted[i])
			{
				cur->idx = i + 1;
				break ;
			}
			cur = cur->prev;
			k++;
		}
		i++;
	}
	free(sorted);
	sorted = NULL;
}

void	prep_stacks(t_head *a_hd, t_head *b_hd, int *nbrs)
{
	init_stack(a_hd, nbrs);
	a_hd->len = nbrs[0];
	init_stack(b_hd, NULL);
	b_hd->len = 0;
	a_hd->t_len = nbrs[0];
	b_hd->t_len = nbrs[0];
}

int	main(int argc, char *argv[])
{
	t_head	a_hd;
	t_head	b_hd;
	t_ops	*ops_lst;
	int		*nbrs;

	nbrs = arg_check(argc, argv);
	if (argc < 2 || nbrs[0] == 1)
	{
		free(nbrs);
		nbrs = NULL;
		return (0);
	}
	prep_stacks(&a_hd, &b_hd, nbrs);
	ops_lst = (t_ops *)ft_calloc(1, sizeof(t_ops));
	if (!ops_lst)
		error_exit(2);
	a_hd.ops = &ops_lst;
	b_hd.ops = &ops_lst;
	put_in_order(&a_hd, get_sorted_array(nbrs));
	sort_stacks(&a_hd, &b_hd, a_hd.t_len);
	write_ops(ops_lst);
	free_alloc(&a_hd, &ops_lst);
	return (0);
}
