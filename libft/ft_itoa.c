/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:58:20 by ghan              #+#    #+#             */
/*   Updated: 2021/05/04 15:58:25 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_cnt(int n)
{
	int	cnt;
	int pos_n;

	cnt = 1;
	if (n == -2147483648)
		pos_n = 2147483647;
	pos_n = -n;
	while (pos_n / 10)
	{
		pos_n /= 10;
		cnt++;
	}
	return (cnt);
}

char		*ft_itoa(int n)
{
	int		cnt;
	char	*ret;

	cnt = n < 0 ? digit_cnt(n) + 1 : digit_cnt(n);
	if (!(ret = (char*)malloc(cnt + 1)))
		return (0);
	ret[cnt] = 0;
	if (n < 0)
	{
		while (cnt)
		{
			ret[cnt-- - 1] = "0123456789"[(n % 10) * -1];
			n /= 10;
		}
		ret[0] = '-';
	}
	else
	{
		while (cnt)
		{
			ret[cnt-- - 1] = "0123456789"[n % 10];
			n /= 10;
		}
	}
	return (ret);
}
