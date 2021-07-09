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
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_head	*a_head;
	t_head	*b_head;
	int		*nbrs;
	int		*hex_cnt;
	int		*keys;

	/* SECTION - print ARGVs */
	// printf("\n\nARGVs are : \n");
	// int k = 1;
	// while (k < argc)
	// 	printf("%s ", argv[k++]);
	// printf("\n\n-----------------------\n\n");
	/* --------------------- */

	nbrs = arg_check(argc, argv);
	if (argc < 2 || nbrs[0] == 1)
	{
		free(nbrs);
		nbrs = NULL;
		return (0);
	}
	init_stack(&a_head, nbrs);
	a_head->len = nbrs[0];
	init_stack(&b_head, NULL);
	b_head->len = 0;

	radix_sort_stacks(&a_head, &b_head);
	// keys = get_qsort_key(nbrs);

	/* SECTION - test print */
	// printf("\n\n-----A_STACK----------\n\n");
	// t_stack *cur = a_head->start->prev;
	// while (cur != a_head->start)
	// {
	// 	printf("%d\n", cur->nbr);
	// 	cur = cur->prev;
	// }
	// printf("%d\n\n", cur->nbr);

	// t_stack *cur_b = b_head->start->prev;
	// while (cur_b != b_head->start)
	// {
	// 	printf("%d\n", cur_b->nbr);
	// 	cur_b = cur_b->prev;
	// }

	free(keys);
	keys = NULL;
	return (0);
}
