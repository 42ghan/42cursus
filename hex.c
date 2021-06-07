/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:06:36 by ghan              #+#    #+#             */
/*   Updated: 2021/05/18 17:06:37 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	fill_zero_hex(t_flist *cur, char **tmp)
{
	char	*z;
	int		z_len;

	z_len = ft_strlen(*tmp);
	if (!cur->prec && cur->width > z_len)
		z_len = cur->width;
	if (cur->prec > z_len)
		z_len = cur->prec;
	z = (char*)ft_calloc(z_len + 1, 1);
	if (z)
	{
		ft_memset(z, '0', z_len);
		strncpy_no_null(z + z_len - ft_strlen(*tmp), *tmp, ft_strlen(*tmp));
	}
	free(*tmp);
	*tmp = z;
}

static void	flags_to_hex(t_flist *cur, char *tmp)
{
	int	len;

	if (cur->zero || cur->prec > (int)ft_strlen(tmp))
		fill_zero_hex(cur, &tmp);
	len = ft_strlen(tmp);
	if (cur->prec > len)
		len = cur->prec;
	if (cur->width > len)
		len = cur->width;
	cur->prnt = (char*)ft_calloc(len + 1, 1);
	if (cur->prnt == NULL)
	{
		free(tmp);
		return ;
	}
	flags_to_ints_hex(cur, tmp, len);
}

static int	hex_cnt(unsigned int n)
{
	int	cnt;

	cnt = 1;
	while (n / 16)
	{
		n /= 16;
		cnt++;
	}
	return (cnt);
}

void		prcss_hex(t_flist *cur, va_list *ap, char f)
{
	unsigned int	n;
	int				cnt;
	char			*tmp;

	n = va_arg(*ap, unsigned int);
	cnt = hex_cnt(n);
	tmp = (char*)ft_calloc(cnt + 1, 1);
	if (tmp == NULL)
		return ;
	while (cnt)
	{
		if (f == 'x')
			tmp[cnt - 1] = "0123456789abcdef"[n % 16];
		else if (f == 'X')
			tmp[cnt - 1] = "0123456789ABCDEF"[n % 16];
		n /= 16;
		cnt--;
	}
	flags_to_hex(cur, tmp);
}
