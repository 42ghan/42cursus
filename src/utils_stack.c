/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:27:51 by ghan              #+#    #+#             */
/*   Updated: 2021/07/05 17:27:51 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    init_stack(t_stack **head, int *nbrs)
{
    int     i;
    t_stack *cur;

    *head = (t_stack *)ft_calloc(1, sizeof(t_stack));
    if (!(*head))
        error_exit(2);
    (*head)->prev = NULL;
    if (nbrs)
    {
        i = 0;
        while (++i < nbrs[0])
        {
            cur = (t_stack *)ft_calloc(1, sizeof(t_stack));
            if (!cur)
                error_exit(2);
            cur->nbr = nbrs[i];
            if (i = 1)
                (*head)->next = cur;
        }
    }
    else
        (*head)->next = NULL;
}
