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

void		flags_to_ints_hex(t_flist *cur, char *tmp, int len)
{
	int	tmp_len;

	tmp_len = ft_strlen(tmp);
	ft_memset(cur->prnt, ' ', len);
	if (ft_strchr(cur->flag, '.') && cur->prec == 0
	&& tmp[0] == '0' && tmp[1] == 0)
	{
		if (cur->width == 0)
		{
			cur->prnt[0] = 0;
			free(tmp);
			return ;
		}
		tmp[0] = 0;
	}
	if (cur->align)
		strncpy_no_null(cur->prnt, tmp, tmp_len);
	else
		strncpy_no_null(cur->prnt + len - tmp_len, tmp, tmp_len);
	free(tmp);
}

static void	fill_zero_prec(t_flist *cur, char **tmp)
{
	char	*z;
	int		z_len;
	int		neg;
	int		o_len;

	if (!(*tmp))
		return ;
	o_len = ft_strlen(*tmp);
	neg = 0;
	z_len = cur->prec;
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

static void	fill_zero(t_flist *cur, char **tmp)
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
	if (cur->width > z_len)
		z_len = cur->width;
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

void		prcss_ints(t_flist *cur, va_list *ap, char f)
{
	char	*tmp;
	int		len;

	if (f == 'd' || f == 'i')
		tmp = ft_itoa(va_arg(*ap, int));
	else
		tmp = ft_uitoa(va_arg(*ap, unsigned int));
	if (cur->zero && !cur->prec)
		fill_zero(cur, &tmp);
	else if (cur->prec > (int)ft_strlen(tmp))
		fill_zero_prec(cur, &tmp);
	if (!tmp)
		return ;
	len = ft_strlen(tmp);
	if (cur->width > len)
		len = cur->width;
	if (tmp[0] == '-' && cur->prec == len)
		len++;
	cur->prnt = (char*)ft_calloc(len + 1, 1);
	if (!cur->prnt)
	{
		free(tmp);
		return ;
	}
	flags_to_ints_hex(cur, tmp, len);
}
