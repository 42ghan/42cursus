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
	while (cnt + sign > 0)
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
	int	idx;
	int zero_len;

	idx = 0;
	if (!cur->align && (len > (int)ft_strlen(tmp)))
		idx = len - ft_strlen(tmp);
	zero_len = 0;
	if (cur->zero || cur->prec > (int)ft_strlen(tmp))
	{
		zero_len = len;
		if (cur->prec && cur->prec < len)
			zero_len = cur->prec;
		ft_memset(cur->prnt + len - idx, '0', zero_len);
		if (tmp[0] == '-')
		{
			if (cur->prec <= (int)ft_strlen(tmp))
				zero_len--;
			cur->prnt[len - zero_len - 1] = '-';
			strncpy_no_null(cur->prnt + idx + 1, tmp + 1, len);
		}
		else
			strncpy_no_null(cur->prnt + idx, tmp, len);
	}
	else
		strncpy_no_null(cur->prnt + idx, tmp, len);
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
	if (cur->prec > len)
		len = cur->prec;
	if (cur->width > len)
		len = cur->width;
	if ((cur->prec >= len) && tmp[0] == '-')
		len++;
	cur->prnt = (char*)ft_calloc(len + 1, 1);
	if (cur->prnt == NULL)
	{
		free(tmp);
		return ;
	}
	ft_memset(cur->prnt, ' ', len);
	flags_to_ints_hex(cur, tmp, len);
	free(tmp);
}
