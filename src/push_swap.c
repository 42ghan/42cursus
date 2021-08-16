/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:09:18 by ghan              #+#    #+#             */
/*   Updated: 2021/07/05 12:09:19 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_alloc(t_head *a_head, t_head *b_head, int *sorted)
{
	t_stack	*cur;

	free(sorted);
	sorted = NULL;
	cur = a_head->start->prev;
	while (a_head->len > 0)
	{
		free(cur);
		cur = cur->prev;
	}
	cur = b_head->start->prev;
	while (b_head->len > 0)
	{
		free(cur);
		cur = cur->prev;
	}
}

void	put_in_order(t_head *a_head, int *sorted)
{
	t_stack	*cur;
	int		i;
	int		k;

	i = 0;
	while (i < a_head->len)
	{
		cur = a_head->start;
		k = 0;
		while (k < a_head->len)
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

int	main(int argc, char *argv[])
{
	t_head	a_head;
	t_head	b_head;
	t_ops	*ops_lst;
	int		*nbrs;
	int		*sorted;

	nbrs = arg_check(argc, argv);
	if (argc < 2 || nbrs[0] == 1)
	{
		free(nbrs);
		nbrs = NULL;
		return (0);
	}
	init_stack(&a_head, nbrs);
	a_head.len = nbrs[0];
	init_stack(&b_head, NULL);
	b_head.len = 0;
	a_head.total_len = nbrs[0];
	b_head.total_len = nbrs[0];
	ops_lst = (t_ops *)ft_calloc(1, sizeof(t_ops));
	if (!ops_lst)
		error_exit(2);
	a_head.ops = &ops_lst;
	b_head.ops = &ops_lst;
	put_in_order(&a_head, get_sorted_array(nbrs));
	sort_stacks(&a_head, &b_head);
	write_ops(ops_lst);
	// int cnt = 0;
	// while (ops_lst->next)
	// {
	// 	ops_lst = ops_lst->next;
	// 	cnt++;
	// }
	// printf("no. of ops : %d\n", cnt);
	/* SECTION - test print */
	// printf("\n\n-----A_STACK----------\n\n");
	// t_stack *cur_a = a_head.start->prev;
	// while (cur_a != a_head.start)
	// {
	// 	printf("%d\n", cur_a->idx);
	// 	cur_a = cur_a->prev;
	// }
	// printf("%d\n\n", cur_a->idx);

	// printf("\n\n-----B_STACK----------\n\n");
	// t_stack *cur_b = b_head.start->prev;
	// while (cur_b != b_head.start)
	// {
	// 	printf("%d\n", cur_b->idx);
	// 	cur_b = cur_b->prev;
	// }
	// printf("%d\n\n", cur_b->idx);

	// free_alloc(&a_head, &b_head, sorted);
	return (0);
}
