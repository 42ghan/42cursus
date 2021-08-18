/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_ints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:12:41 by ghan              #+#    #+#             */
/*   Updated: 2021/07/06 16:12:41 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	bit_value(unsigned int nbr, int bit)
{
	int	mask;

	mask = 1 << bit;
	if (nbr & mask)
		return (1);
	return (0);
}

static unsigned int	*counting_sort(unsigned int *arr, int bit, int len)
{
	unsigned int	indices[2];
	unsigned int	*ret;
	int				which_bit;
	int				cnt[2];
	int				i;

	ret = (unsigned int *)ft_calloc(len, sizeof(unsigned int));
	if (!ret)
		error_exit(2);
	cnt[0] = 0;
	cnt[1] = 1;
	i = 0;
	while (i < len)
		cnt[bit_value(arr[i++], bit)]++;
	indices[0] = 0;
	indices[1] = cnt[0];
	i = -1;
	while (++i < len)
	{
		which_bit = bit_value(arr[i], bit);
		ret[indices[which_bit]] = arr[i];
		indices[which_bit]++;
	}
	return (ret);
}

static unsigned int	*radix_sort(unsigned int *u_nbrs, int len)
{
	int				bit;
	unsigned int	*tmp;

	bit = 0;
	while (bit < 32)
	{
		tmp = u_nbrs;
		u_nbrs = counting_sort(u_nbrs, bit++, len);
		free(tmp);
		tmp = NULL;
	}
	return (u_nbrs);
}

int	*get_sorted_array(int *nbrs)
{
	unsigned int	*u_nbrs;
	int				*sorted;
	int				*keys;

	u_nbrs = int_to_unsigned_arr(nbrs);
	u_nbrs = radix_sort(u_nbrs, nbrs[0]);
	sorted = unsigned_to_int_arr(nbrs, u_nbrs);
	free(nbrs);
	nbrs = NULL;
	free(u_nbrs);
	u_nbrs = NULL;
	return (sorted);
}
