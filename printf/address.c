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

static void	align_l_r(t_flist *spec, int pos, unsigned long long addr, int len)
{
	int	to;

	if (len == 1)
	{
		spec->prnt[pos - 1] = '0';
		spec->prnt[pos] = 'x';
		spec->prnt[pos + 1] = 0;
		return ;
	}
	to = pos - len;
	while (pos >= to)
	{
		spec->prnt[pos] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		pos--;
	}
	spec->prnt[pos--] = 'x';
	spec->prnt[pos] = '0';
}

static int	cnt_addr_len(unsigned long long addr)
{
	int	cnt;

	cnt = 1;
	while (addr / 16)
	{
		addr /= 16;
		cnt++;
	}
	return (cnt);
}

void		prcss_addr(t_flist *spec, va_list *ap)
{
	unsigned long long	addr;
	int					len;
	int					act_len;

	addr = (unsigned long long)va_arg(*ap, void*);
	act_len = cnt_addr_len(addr);
	if (addr == 0 && spec->isprec && !spec->prec)
		act_len = 0;
	len = act_len + 2;
	if (spec->width > len)
		len = spec->width;
	spec->prnt = (char*)ft_calloc(len + 1, 1);
	if (!spec->prnt)
		return ;
	ft_memset(spec->prnt, '0', len);
	if (spec->align == 1 || !spec->zero)
		ft_memset(spec->prnt, ' ', len);
	if (spec->align == 1)
		align_l_r(spec, act_len + 1, addr, act_len - 1);
	else if (spec->align == 0)
		align_l_r(spec, len - 1, addr, act_len - 1);
}
