/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:06:26 by ghan              #+#    #+#             */
/*   Updated: 2021/05/18 17:06:26 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	digit_cnt(int n)
{
	int	cnt;
	int pos_n;

	cnt = 1;
	if (n == -2147483648)
		pos_n = 2147483647;
	pos_n = n;
	if (n < 0)
		pos_n = -n;
	while (pos_n / 10)
	{
		pos_n /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*ft_itoa(int n)
{
	int		cnt;
	int		sign;
	char	*ret;

	sign = 1;
	cnt = digit_cnt(n);
	if (n < 0)
	{
		cnt++;
		sign = -1;
	}
	ret = (char*)ft_calloc(cnt + 1, 1);
	if (!ret)
		return (NULL);
	if (n < 0)
		ret[0] = '-';
	while (cnt)
	{
		ret[cnt - 1] = "0123456789"[n % 10 * sign];
		n /= 10;
		cnt--;
	}
	return (ret);
}

static char	*ft_uitoa(unsigned int n)
{
	int		cnt;
	char	*ret;

	cnt = 1;
	while (n / 10)
	{
		n /= 10;
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

void		flags_to_ints_hex(t_flist *cur, char *tmp, int len)
{
	unsigned int	zero_len;
	unsigned int	idx;

	zero_len = 0;
	ft_memset(cur->prnt, ' ', len);
	if (cur->zero)
		ft_memset(cur->prnt, '0', len);
	if (cur->prec > ft_strlen(tmp))
		zero_len = cur->prec - ft_strlen(tmp);
	if (cur->align)
		idx = 0;
	else
		idx = len - ft_strlen(tmp) - zero_len;
	while (zero_len > 0)
	{
		cur->prnt[idx] = '0';
		idx++;
		zero_len--;
	}
	ft_memmove(cur->prnt + idx, tmp, ft_strlen(tmp));
	free(tmp);
}

void		prcss_ints(t_flist *cur, va_list *ap, char f)
{
	char	*tmp;
	int		len;

	if (f == 'd' || f == 'i')
		tmp = ft_itoa(va_arg(*ap, int));
	else
		tmp = ft_uitoa(va_arg(*ap, unsigned int));
	if (!tmp)
		return ;
	len = ft_strlen(tmp);
	if ((cur->width > len) || (cur->prec > len))
	{
		if (cur->width > cur->prec)
			len = cur->width;
		else
			len = cur->prec;
	}
	cur->prnt = (char*)ft_calloc(len + 1, 1);
	if (cur->prnt == NULL)
	{
		free(tmp);
		return ;
	}
	flags_to_ints_hex(cur, tmp, len);
}
