/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:05:59 by ghan              #+#    #+#             */
/*   Updated: 2021/05/18 17:05:59 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	null_addr(t_flist *spec)
{
	int	idx;

	idx = 0;
	if (ft_strchr(spec->flag, '.'))
	{
		if (spec->width > 2)
			idx = spec->width - 2;
		spec->prnt[idx++] = '0';
		spec->prnt[idx++] = 'x';
		spec->prnt[idx] = 0;
	}
	else
	{
		if (spec->width > 3)
			idx = spec->width - 3;
		spec->prnt[idx++] = '0';
		spec->prnt[idx++] = 'x';
		spec->prnt[idx] = '0';
	}
}

static void	align_left_or_right(t_flist *spec, int pos, long long addr)
{
	int	to;

	to = pos - 8;
	while (pos >= to)
	{
		spec->prnt[pos] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		pos--;
	}
	spec->prnt[pos--] = 'x';
	spec->prnt[pos] = '0';
}

void		prcss_addr(t_flist *spec, va_list *ap)
{
	long long		addr;
	int				len;

	addr = (long long)va_arg(*ap, void*);
	len = 11;
	if (addr == 0)
		len = 3;
	else if (spec->width > len)
		len = spec->width;
	spec->prnt = (char*)ft_calloc(len + 1, 1);
	if (!spec->prnt)
		return ;
	ft_memset(spec->prnt, '0', len);
	if (spec->align == 1 || !spec->zero)
		ft_memset(spec->prnt, ' ', len);
	if (addr == 0)
		null_addr(spec);
	else if (spec->align == 1)
		align_left_or_right(spec, 10, addr);
	else if (spec->align == 0)
		align_left_or_right(spec, len - 1, addr);
}
