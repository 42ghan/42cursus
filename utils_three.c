/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:02:06 by ghan              #+#    #+#             */
/*   Updated: 2021/06/07 14:02:07 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		digit_cnt(int n)
{
	int	cnt;
	int pos_n;

	cnt = 1;
	if (n == -2147483648)
		pos_n = 2147483647;
	pos_n = n;
	if (n < 0)
	{
		cnt++;
		pos_n = -n;
	}
	while (pos_n / 10)
	{
		pos_n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	unsigned int	un;
	int				cnt;
	int				sign;
	char			*ret;

	sign = 0;
	un = n;
	if (n < 0)
	{
		sign = 1;
		un = n * (-1);
	}
	cnt = digit_cnt(n);
	ret = (char*)ft_calloc(cnt + 1, 1);
	if (!ret)
		return (NULL);
	if (n < 0)
		ret[0] = '-';
	while (cnt > sign)
	{
		ret[cnt - 1] = "0123456789"[(un % 10)];
		un /= 10;
		cnt--;
	}
	return (ret);
}

char	*ft_uitoa(unsigned int n)
{
	int				cnt;
	char			*ret;
	unsigned int	n_cpy;

	cnt = 1;
	n_cpy = n;
	while (n_cpy / 10)
	{
		n_cpy /= 10;
		cnt++;
	}
	ret = (char*)ft_calloc(cnt + 1, 1);
	if (!ret)
		return (NULL);
	while (cnt)
	{
		ret[cnt - 1] = "0123456789"[n % 10];
		n /= 10;
		cnt--;
	}
	return (ret);
}

void	prcss_perc(t_flist *cur)
{
	int	len;

	len = 1;
	if (cur->width > len)
		len = cur->width;
	cur->prnt = (char*)ft_calloc(len + 1, 1);
	if (!cur->prnt)
		return ;
	ft_memset(cur->prnt, '0', len);
	if (!cur->zero)
		ft_memset(cur->prnt, ' ', len);
	if (cur->align)
		cur->prnt[0] = '%';
	else
		cur->prnt[len - 1] = '%';
}
