/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:58:20 by ghan              #+#    #+#             */
/*   Updated: 2021/09/22 22:43:43 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_cnt(int n)
{
	int	cnt;
	int	pos_n;

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

char	*ft_itoa(int n)
{
	int		cnt;
	char	*ret;

	cnt = digit_cnt(n);
	if (n < 0)
		cnt++;
	ret = (char *)ft_calloc(cnt + 1, sizeof(char));
	if (!ret)
		return (NULL);
	while (cnt)
	{
		if (n < 0)
			ret[cnt - 1] = "0123456789"[n % 10 * -1];
		else
			ret[cnt - 1] = "0123456789"[n % 10];
		cnt--;
		n /= 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ret);
}
