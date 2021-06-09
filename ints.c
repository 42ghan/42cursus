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

void		flags_to_ints_hex(t_flist *spec, char *tmp, int len)
{
	int	tmp_len;

	tmp_len = ft_strlen(tmp);
	ft_memset(spec->prnt, ' ', len);
	if (spec->isprec && !spec->prec && tmp[0] == '0' && !tmp[1])
	{
		if (spec->width == 0)
		{
			spec->prnt[0] = 0;
			free(tmp);
			return ;
		}
		tmp[0] = 0;
	}
	if (spec->align)
		strncpy_no_null(spec->prnt, tmp, tmp_len);
	else
		strncpy_no_null(spec->prnt + len - tmp_len, tmp, tmp_len);
	free(tmp);
}

static void	fill_zero_prec(t_flist *spec, char **tmp)
{
	char	*z;
	int		z_len;
	int		o_len;
	int		neg;

	if (!(*tmp))
		return ;
	o_len = ft_strlen(*tmp);
	neg = 0;
	z_len = spec->prec;
	if (*tmp[0] == '-')
		z_len++;
	z = (char*)ft_calloc(z_len + 1, 1);
	if (z)
	{
		ft_memset(z, '0', z_len);
		if (*tmp[0] == '-')
		{
			neg = 1;
			z[0] = '-';
		}
		strncpy_no_null(z + z_len + neg - o_len, *tmp + neg, o_len - neg);
	}
	free(*tmp);
	*tmp = z;
}

static void	fill_zero(t_flist *spec, char **tmp)
{
	char	*z;
	int		z_len;
	int		o_len;
	int		neg;

	if (!(*tmp))
		return ;
	o_len = ft_strlen(*tmp);
	neg = 0;
	z_len = o_len;
	if (spec->width > z_len)
		z_len = spec->width;
	z = (char*)ft_calloc(z_len + 1, 1);
	if (z)
	{
		ft_memset(z, '0', z_len);
		if (*tmp[0] == '-')
		{
			neg = 1;
			z[0] = '-';
		}
		strncpy_no_null(z + z_len + neg - o_len, *tmp + neg, o_len - neg);
	}
	free(*tmp);
	*tmp = z;
}

void		prcss_ints(t_flist *spec, va_list *ap, char f)
{
	char	*tmp;
	int		len;

	if (f == 'd' || f == 'i')
		tmp = ft_itoa(va_arg(*ap, int));
	else
		tmp = ft_uitoa(va_arg(*ap, int));
	if (spec->zero && !spec->isprec)
		fill_zero(spec, &tmp);
	else if (spec->prec >= (int)ft_strlen(tmp))
		fill_zero_prec(spec, &tmp);
	if (!tmp)
		return ;
	len = ft_strlen(tmp);
	if (spec->width > len)
		len = spec->width;
	if (tmp[0] == '-' && spec->prec == len)
		len++;
	spec->prnt = (char*)ft_calloc(len + 1, 1);
	if (!spec->prnt)
	{
		free(tmp);
		return ;
	}
	flags_to_ints_hex(spec, tmp, len);
}
