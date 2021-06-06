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

static void			check_prec(t_flist *cur, char *p, va_list ap_cpy)
{
	if (ft_isdigit(*p))
	{
		cur->prec = unsigned_atoi(p);
		if ((cur->prec == 0) && (*p != '0'))
			cur->prec = -1;
	}
	else if (*p == '*')
		cur->prec = va_arg(ap_cpy, int);
	else if (*p)
		cur->prec = -1;
}

static void			check_width(t_flist *cur, char *w, va_list ap_cpy)
{
	if (*w == '0' || *w == '-')
	{
		if (*w == '0')
			cur->zero = 1;
		else if (*w == '-')
			cur->align = 1;
		w++;
	}
	if (ft_isdigit(*w))
	{
		cur->width = unsigned_atoi(w);
		if ((cur->width == 0) && (*w != '0'))\
		cur->width = -1;
	}
	else if (*w == '*')
	{
		cur->width = va_arg(ap_cpy, int);
		if (cur->width < 0)
		{
			cur->align = 1;
			cur->width *= -1;
		}
	}
	else if (*w)
		cur->width = -1;
}

static void			cnt_ast(t_flist *cur, va_list *ap)
{
	unsigned int	i;
	int				n_ast;

	i = 0;
	while (cur->flag[i])
	{
		if (cur->flag[i] == '*')
			cur->ast_cnt++;
		i++;
	}
	n_ast = cur->ast_cnt;
	while (n_ast)
	{
		va_arg(*ap, int);
		n_ast--;
	}
}

void				check_flags(t_flist *cur, va_list *ap)
{
	va_list			ap_cpy;
	unsigned int	dot_idx;
	char			*w;
	char			*p;

	va_copy(ap_cpy, *ap);
	cnt_ast(cur, ap);
	dot_idx = 0;
	while (cur->flag[dot_idx] && cur->flag[dot_idx] != '.')
		dot_idx++;
	w = ft_strndup(cur->flag, dot_idx);
	check_width(cur, w, ap_cpy);
	free(w);
	if (dot_idx == ft_strlen(cur->flag))
		p = NULL;
	else
	{
		p = ft_substr(cur->flag, dot_idx + 1, ft_strlen(cur->flag)-dot_idx);
		check_prec(cur, p, ap_cpy);
		free(p);
	}
}