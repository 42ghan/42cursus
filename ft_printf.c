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

static int	by_format(t_flist *cur, va_list *ap, char f)
{
	if (cur->flag[0] != 0)
		check_flags(cur, ap);
	if ((cur->width >= 0) && (cur->prec >= 0))
	{
		if (f == '%')
			cur->prnt = ft_strndup("%", 1);
		else if  (f == 'p')
			prcss_addr(cur, ap);
		else if ((f == 'c') || (f == 's'))
			prcss_c_or_str(cur, ap, f);
		else if ((f == 'd') || (f == 'i') || (f == 'u'))
			prcss_ints(cur, ap, f);
		else if (f == 'x' || f == 'X')
			prcss_hex(cur, ap, f);
		while (cur->ast_cnt)
		{
			va_arg(*ap, int);
			cur->ast_cnt--;
		}
	}
	if ((cur->prnt) == NULL)
		return (0);
	return (1);
}

static int	form_idx_finder(char c)
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

static int	fill_form(char *format, t_flist **forms, unsigned int start)
{
	t_flist			*elem;
	unsigned int	f_idx;

	elem = flist_init();
	if (!elem)
		return (0);
	elem->start = start;
	elem->end = start + 1;
	while (format[elem->end])
	{
		f_idx = form_idx_finder(format[elem->end]);
		if (f_idx >= 0 && f_idx <= 8)
		{
			elem->form = "cspdiuxX%"[f_idx];
			break ;
		}
		elem->end++;
	}
	elem->flag = ft_substr(format, elem->start + 1,
		elem->end - elem->start - 1);
	if (!elem->flag)
		return (0);
	flist_add_back(forms, elem);
	return (elem->end);
}

static int	check_formats(char *format, t_flist **forms)
{
	unsigned int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%') // Format specifier found
		{
			i = fill_form(format, forms, i); // Create element of forms list with details about the format specifier
			if (i == 0)
			{
				clear_list(forms);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

// Where everything starts
int			ft_printf(const char *format, ...)
{
	t_flist	*forms;
	t_flist *cur;
	va_list ap;
	size_t	cnt;

	cnt = 0;
	forms = flist_init(); // Initialize flist
	if (!forms)
		return (0);
	if (check_formats((char*)format, &forms) == 0) // Check provided formats and fill flist
		return (0);
	va_start(ap, format);
	cur = forms->next;
	while (cur)
	{
		if (by_format(cur, &ap, cur->form) == 0)
			break ;
		cur = cur->next;
	}
	va_end(ap);
	if (!cur)
		cnt = print_str((char*)format, forms);
	clear_list(&forms);
	return (cnt);
}