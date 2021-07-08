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
	int		*keys;

	nbrs = arg_check(argc, argv);
	if (argc < 2 || nbrs[0] == 1)
	{
		free(nbrs);
		nbrs = NULL;
		return (0);
	}
	int i = 1;
	init_stack(&a_head, nbrs);
	a_head->len = nbrs[0];
	init_stack(&b_head, NULL);
	b_head->len = 0;
	keys = get_qsort_key(nbrs);
	qsort_stack_large(&a_head, &b_head, keys[1]);

	/* TODO - fix qsort_stack_mid */
	qsort_stack_mid(&a_head, &b_head, keys[0]);
	move_small(&a_head, &b_head);

	/* SECTION - test print */
	t_stack *cur = a_head->start->prev;
	while (cur != a_head->start)
	{
		printf("%d\n", cur->nbr);
		cur = cur->prev;
	}
	printf("%d\n\n", cur->nbr);
	/* --------------------- */

	free(keys);
	keys = NULL;
	return (0);
}
