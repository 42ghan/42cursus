/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:25:41 by ghan              #+#    #+#             */
/*   Updated: 2021/06/04 20:25:42 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				clear_list(t_flist **forms)
{
	t_flist	*cur;

	cur = *forms;
	while (cur)
	{
		if (cur->flag)
			free(cur->flag);
		cur->flag = NULL;
		if (cur->prnt)
			free(cur->prnt);
		cur->prnt = NULL;
		cur = cur->next;
		free(*forms);
		*forms = cur;
	}
}

static unsigned int	print_elem(t_flist **cur, size_t *cnt)
{
	unsigned int	next_idx;

	write(1, (*cur)->prnt, ft_strlen((*cur)->prnt));
	*cnt += ft_strlen((*cur)->prnt);
	next_idx = (*cur)->end + 1;
	*cur = (*cur)->next;
	return (next_idx);
}

size_t				print_str(char *str, t_flist *forms)
{
	size_t			cnt;
	unsigned int	i;
	t_flist			*cur;

	cnt = 0;
	i = 0;
	cur = forms->next;
	while (str[i])
	{
		if (cur && i == cur->start)
		{
			i = print_elem(&cur, &cnt);
			if (!i)
				return (0);
		}
		if (!str[i])
			break ;
		write(1, &str[i], 1);
		cnt++;
		i++;
	}
	return (cnt);
}
