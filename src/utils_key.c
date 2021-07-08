/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:01:28 by ghan              #+#    #+#             */
/*   Updated: 2021/07/07 17:01:29 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

unsigned int	*int_to_unsigned_arr(int *nbrs)
{
	unsigned int	*ret;
	int				i;

	ret = (unsigned int *)ft_calloc(nbrs[0], sizeof(unsigned int));
	if (!ret)
		error_exit(2);
	i = 1;
	while (i < nbrs[0] + 1)
	{
		ret[i - 1] = (unsigned int)nbrs[i] + 2147483648;
		i++;
	}
	return (ret);
}

int	*unsigned_to_int_arr(int *nbrs, unsigned int *u_nbrs)
{
	int	*ret;
	int	i;

	ret = (int *)ft_calloc(nbrs[0], sizeof(int));
	if (!ret)
		error_exit(2);
	i = 0;
	while (i < nbrs[0])
	{
		ret[i] = u_nbrs[i] - 2147483648;
		i++;
	}
	return (ret);
}
