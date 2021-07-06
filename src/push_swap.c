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

int	main(int argc, char *argv[])
{
	t_head	*a_head;
	t_head	*b_head;
	int		*nbrs;
	int		key;

	if (argc <= 2)
		return (0);
	nbrs = arg_check(argc, argv);
	init_stack(&a_head, nbrs);
	init_stack(&b_head, NULL);
	// key = pre_sort(nbrs);
	return (0);
}
