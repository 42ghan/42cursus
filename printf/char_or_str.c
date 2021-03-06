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

static char	*null_string(void)
{
	char	*tmp;

	tmp = (char*)ft_calloc(7, 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '(';
	tmp[1] = 'n';
	tmp[2] = 'u';
	tmp[3] = 'l';
	tmp[4] = 'l';
	tmp[5] = ')';
	return (tmp);
}

static void	flags_to_str(t_flist *spec, char *tmp)
{
	int	len;
	int	idx;
	int	str_len;

	if (!tmp)
		tmp = null_string();
	if (!tmp)
		return ;
	len = ft_strlen(tmp);
	if (spec->isprec && spec->prec < len)
		len = spec->prec;
	str_len = len;
	if (spec->width > len)
		len = spec->width;
	spec->prnt = (char*)ft_calloc(len + 1, 1);
	if (!spec->prnt)
		return ;
	ft_memset(spec->prnt, ' ', len);
	idx = 0;
	if (!spec->align && len > str_len)
		idx = len - str_len;
	strncpy_no_null(spec->prnt + idx, tmp, str_len);
}

void		prcss_c_or_str(t_flist *spec, va_list *ap, char f)
{
	char			*tmp;
	int				len;

	if (f == 'c')
	{
		len = 1;
		if (spec->width > len)
			len = spec->width;
		spec->len = len;
		tmp = (char*)ft_calloc(len + 1, 1);
		if (!tmp)
			return ;
		ft_memset(tmp, ' ', len);
		if (len == 1 || spec->align)
			tmp[0] = va_arg(*ap, int);
		else
			tmp[len - 1] = va_arg(*ap, int);
		spec->prnt = tmp;
	}
	else
	{
		tmp = va_arg(*ap, char*);
		flags_to_str(spec, tmp);
	}
}
