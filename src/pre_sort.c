/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
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
	int mask;

	mask = 1 << bit;
	if (nbr & mask)
		return (1);
	return (0);
}

static unsigned int	*counting_sort(unsigned int *arr, int bit, int len)
{
	unsigned int	indices[2];
	unsigned int	*ret;
	int				cnt[2];
	int				i;
	int				which_bit;

	ret = malloc(sizeof(unsigned int) * len);
	cnt[0] = 0;
	cnt[1] = 1;
	i = 0;
	while (i < len)
		cnt[bit_value(arr[i++], bit)] += 1;
	indices[0] = 0;
	indices[1] = cnt[0];
	i = 0;
	while (i < len)
	{
		which_bit = bit_value(arr[i], bit);
		ret[indices[which_bit]] = arr[i];
		indices[which_bit]++;
		i++;
	}
	return (ret);
}

// static unsigned int	*change_sign_map(unsigned int *nbrs, int flag)
// {
// 	unsigned int	*ret;
// 	long long		sub_or_add;
// 	int				i;

// 	ret = malloc(sizeof(unsigned int) * nbrs[0]);
// 	sub_or_add = 2147483648;
// 	if (flag)
// 		sub_or_add = -2147483648;
// 	i = 1;
// 	while (i < nbrs[0])
// 	{
// 		ret[i - 1] = (unsigned int)nbrs[i] + sub_or_add;
// 		i++;
// 	}
// 	return (ret);
// }

static unsigned int	*radix_sort(unsigned int *u_nbrs, int len)
{
	int	bit;

	bit = 0;
	while (bit < 32)
		u_nbrs = counting_sort(u_nbrs, bit++, len);
	return (u_nbrs);
}

// int	get_qsort_key(int *nbrs)
// {
// 	unsigned int	*u_nbrs;

// 	u_nbrs = change_sign_map(nbrs, 0);
// 	radix_sort(u_nbrs, nbrs[0]);
// }
#include <stdio.h>
int main(void)
{
	unsigned int arr[6];
	arr[0] = 5;
	arr[1] = 2147483647;
	arr[2] = 0;
	arr[3] = 2147483648;
	arr[4] = 400;
	arr[5] = 2345;
	unsigned int	*arr_r;
	int i = 0;
	arr_r = radix_sort(arr, 5);
	while (i < 5)
		printf("%u\n", arr_r[i++]);
}