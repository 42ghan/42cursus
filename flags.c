/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:35:09 by ghan              #+#    #+#             */
/*   Updated: 2021/06/04 20:35:10 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned int	unsigned_atoi(const char *str)
{
	unsigned int	ret;
	unsigned int	i;

	ret = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	return (ret);
}

static void			check_prec(t_flist *spec, char *p, va_list *ap_cpy)
{
	if (!p)
	{
		spec->prec = -1;
		return ;
	}
	spec->isprec = 1;
	if (ft_isdigit(*p))
	{
		spec->prec = unsigned_atoi(p);
		if ((spec->prec == 0) && (*p != '0'))
			spec->prec = -1;
	}
	else if (*p == '*')
	{
		spec->prec = va_arg(*ap_cpy, int);
		if (spec->prec < 0)
		{
			spec->isprec = 0;
			spec->prec = 0;
		}
	}
}

static void			check_width(t_flist *spec, char *w, va_list *ap_cpy)
{
	if (*w == '0' || *w == '-')
	{
		if (*w == '0')
			spec->zero = 1;
		else if (*w == '-')
			spec->align = 1;
		w++;
		while (*w == '0' || *w == '-')
			w++;
	}
	if (ft_isdigit(*w))
	{
		spec->width = unsigned_atoi(w);
		if ((spec->width == 0) && (*w != '0'))
			spec->width = -1;
	}
	else if (*w == '*')
	{
		spec->width = va_arg(*ap_cpy, int);
		if (spec->width < 0)
		{
			spec->align = 1;
			spec->width *= -1;
		}
	}
}

static void			cnt_ast(t_flist *spec, va_list *ap)
{
	unsigned int	i;
	int				n_ast;

	n_ast = 0;
	i = 0;
	while (spec->flag[i])
	{
		if (spec->flag[i] == '*')
			n_ast++;
		i++;
	}
	while (n_ast)
	{
		va_arg(*ap, int);
		n_ast--;
	}
}

void				check_flags(t_flist *spec, va_list *ap)
{
	va_list			ap_cpy;
	unsigned int	dot_idx;
	char			*w;
	char			*p;

	va_copy(ap_cpy, *ap);
	cnt_ast(spec, ap);
	dot_idx = 0;
	while (spec->flag[dot_idx] && spec->flag[dot_idx] != '.')
		dot_idx++;
	w = ft_strndup(spec->flag, dot_idx);
	if (!w)
	{
		spec->width = -1;
		return ;
	}
	check_width(spec, w, &ap_cpy);
	free(w);
	if (dot_idx != ft_strlen(spec->flag))
	{
		p = ft_substr(spec->flag, dot_idx + 1, ft_strlen(spec->flag) - dot_idx);
		check_prec(spec, p, &ap_cpy);
		free(p);
	}
}
