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

static void	fill_zero_hex(t_flist *spec, char **tmp)
{
	char	*z;
	int		z_len;

	z_len = ft_strlen(*tmp);
	if (!spec->prec && spec->width > z_len)
		z_len = spec->width;
	if (spec->prec > z_len)
		z_len = spec->prec;
	z = (char*)ft_calloc(z_len + 1, 1);
	if (z)
	{
		ft_memset(z, '0', z_len);
		strncpy_no_null(z + z_len - ft_strlen(*tmp), *tmp, ft_strlen(*tmp));
	}
	free(*tmp);
	*tmp = z;
}

static void	flags_to_hex(t_flist *spec, char *tmp)
{
	int	len;

	if (spec->zero || spec->prec > (int)ft_strlen(tmp))
		fill_zero_hex(spec, &tmp);
	len = ft_strlen(tmp);
	if (spec->prec > len)
		len = spec->prec;
	if (spec->width > len)
		len = spec->width;
	spec->prnt = (char*)ft_calloc(len + 1, 1);
	if (spec->prnt == NULL)
	{
		free(tmp);
		return ;
	}
	flags_to_ints_hex(spec, tmp, len);
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

void		prcss_hex(t_flist *spec, va_list *ap, char f)
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
	flags_to_hex(spec, tmp);
}
