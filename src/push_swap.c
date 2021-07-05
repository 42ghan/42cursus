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
	t_stack	*a_stack;
	t_stack	*b_stack;

	init_stack(&a_stack, arg_check(argc, argv));
	init_stack(&b_stack, NULL);
	return (0);
}
