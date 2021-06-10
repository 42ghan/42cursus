/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:10:36 by ghan              #+#    #+#             */
/*   Updated: 2021/06/04 17:10:36 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		by_format(t_flist *spec, va_list *ap, char f, size_t *cnt)
{
	if (spec->flag[0] != 0)
		check_flags(spec, ap);
	if (spec->zero && spec->align)
		spec->zero = 0;
	if ((spec->width >= 0) && (spec->prec >= 0))
	{
		if (f == '%')
			prcss_perc(spec);
		else if (f == 'p')
			prcss_addr(spec, ap);
		else if ((f == 'c') || (f == 's'))
			prcss_c_or_str(spec, ap, f);
		else if ((f == 'd') || (f == 'i') || (f == 'u'))
			prcss_ints(spec, ap, f);
		else if ((f == 'x') || (f == 'X'))
			prcss_hex(spec, ap, f);
	}
	if ((spec->prnt) == NULL)
	{
		free(spec->flag);
		return (-1);
	}
	*cnt += print_and_count(spec);
	return (1);
}

static size_t	form_idx_finder(char c)
{
	unsigned int	i;

	i = 0;
	while (i < 9)
	{
		if (c == "cspdiuxX%"[i])
			return (i);
		i++;
	}
	return (i);
}

static int		fill_form(char *format, unsigned int start, t_flist *spec)
{
	unsigned int	f_idx;

	spec->start = start;
	spec->end = start + 1;
	while (format[spec->end])
	{
		f_idx = form_idx_finder(format[spec->end]);
		if (f_idx >= 0 && f_idx <= 8)
		{
			spec->form = "cspdiuxX%"[f_idx];
			break ;
		}
		spec->end++;
	}
	spec->flag = ft_substr(format, spec->start + 1,
	spec->end - spec->start - 1);
	if (!spec->flag)
		return (-1);
	return (spec->end);
}

static size_t	print_by_format(char *format, va_list *ap)
{
	int		i;
	size_t	cnt;
	t_flist	spec;

	cnt = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			spec_initialize(&spec);
			i = fill_form(format, i, &spec);
			if (i == -1 || by_format(&spec, ap, spec.form, &cnt) == -1)
				return (-1);
		}
		else
		{
			write(1, &format[i], 1);
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	cnt;

	cnt = 0;
	va_start(ap, format);
	cnt = print_by_format((char*)format, &ap);
	va_end(ap);
	return (cnt);
}
