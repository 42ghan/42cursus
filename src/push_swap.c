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

int     *digits_cnt(t_head **a_head)
{
    t_stack         *cur;
    unsigned int    u_nbr;
    int             *hex_cnt;
    int             cnt;
	int				i;

    hex_cnt = (int *)ft_calloc(8, sizeof(int));
    if (!hex_cnt)
        error_exit(2);
    cur = (*a_head)->start->prev;
	i = -1;
    while (++i < (*a_head)->len)
    {
        cnt = 1;
        u_nbr = cur->u_nbr;
        while (u_nbr / 16)
        {
            u_nbr /= 16;
            cnt++;
        }
        hex_cnt[cnt - 1]++;
        cur->prev;
    }
    return (hex_cnt);
}

int	main(int argc, char *argv[])
{
	t_head	*a_head;
	t_head	*b_head;
	int		*nbrs;
	int		*hex_cnt;
	int		*keys;

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
	hex_cnt = digits_cnt(a_head);
	radix_sort_stacks(a_head, b_head, hex_cnt);
	// keys = get_qsort_key(nbrs);

	/* SECTION - test print */
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
