/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_or_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:06:13 by ghan              #+#    #+#             */
/*   Updated: 2021/05/18 17:06:14 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	flags_to_str(t_flist *cur, char *tmp)
{
	int	len;
	int	idx;

	len = ft_strlen(tmp);
	if ((cur->width > len) || (cur->prec > len))
	{
		if (cur->width > cur->prec)
			len = cur->width;
		else
			len = cur->prec;
	}
	cur->prnt = (char*)ft_calloc(len + 1, 1);
	if (!cur->prnt)
	{
		free(tmp);
		return ;
	}
	ft_memset(cur->prnt, ' ', len);
	idx = 0;
	if (!cur->align)
		idx = len - ft_strlen(tmp);
	ft_memmove(cur->prnt + idx, tmp, ft_strlen(tmp));
}

void		prcss_c_or_str(t_flist *cur, va_list *ap, char f)
{
	char			*tmp;
	int				len;

	if (f == 'c')
	{
		len = 1;
		if (cur->width > len)
			len = cur->width;
		tmp = (char*)ft_calloc(len + 1, 1);
		if (!tmp)
			return ;
		ft_memset(tmp, ' ', len);
		if (len == 1)
			tmp[0] = va_arg(*ap, int);
		else
			tmp[len - 1] = va_arg(*ap, int);
		cur->prnt = tmp;
	}
	else
	{
		tmp = va_arg(*ap, char*);
		flags_to_str(cur, tmp);
	}
}
