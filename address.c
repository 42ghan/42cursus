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

static void	align_left_or_right(t_flist *cur, int pos, long long addr)
{
	unsigned int	to;

	to = pos - 11;
	while (pos >= to)
	{
		cur->prnt[pos] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		pos--;
	}
	cur->prnt[pos--] = 'x';
	cur->prnt[pos] = '0';
}

void		prcss_address(t_flist *cur, va_list *ap)
{
	long long		addr;
	unsigned int	idx;
	int				len;

	addr = (long long)va_arg(*ap, void*);
	len = 14;
	if (cur->width > len)
		len = cur->width;
	cur->prnt = (char*)ft_calloc(len + 1, 1);
	if (!cur->prnt)
		return ;
	ft_memset(cur->prnt, '0', len);
	if (cur->align == 1 || !cur->zero)
		ft_memset(cur->prnt, ' ', len);
	if (cur->align == 1)
		align_left_or_right(cur, 13, addr);
	else if (cur->align == 0)
		align_left_or_right(cur, len - 1, addr);
}
