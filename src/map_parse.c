/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:24:52 by ghan              #+#    #+#             */
/*   Updated: 2021/06/23 23:24:54 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	epc_cnt(int *exit, int *start, int *collect, char c)
{
	if (c == 'E')
		(*exit)++;
	if (c == 'P')
		(*start)++;
	if (c == 'C')
		(*collect)++;
}

static int	check_ln_valid(t_ln_lst *cur, int *exit, int *start, int *collect)
{
	int		i;

	i = 0;
	if (cur->next && (cur->len != cur->next->len))
		return (0);
	while (*(cur->line + i))
	{
		if (cur->line_num == 1 || cur == ft_ln_lstlast(cur))
		{
			if (*(cur->line + i) != '1')
				return (0);
		}
		else
		{
			if (*(cur->line) != '1' || *(cur->line + cur->len - 1) != '1')
				return (0);
			if (*(cur->line + i) != '1' && *(cur->line + i) != '0' &&
			*(cur->line + i) != 'E' && *(cur->line + i) != 'P'
			&& *(cur->line + i) != 'C')
				return (0);
			epc_cnt(exit, start, collect, *(cur->line + i));
		}
		i++;
	}
	return (1);
}

int			check_map_validity(t_ln_lst **head)
{
	int			exit;
	int			start;
	int			collect;
	t_ln_lst	*cur;

	if (!(*head))
		return (0);
	exit = 0;
	start = 0;
	collect = 0;
	cur = (*head)->next;
	while (cur)
	{
		if (!check_ln_valid(cur, &exit, &start, &collect) ||
		(!cur->next && (exit != 1 || start != 1 || !collect)))
		{
			clear_ln_lst(head);
			return (0);
		}
		cur = cur->next;
	}
	return (1);
}

static int	new_then_addback(t_ln_lst **head, char *ln, int cnt)
{
	t_ln_lst	*cur;

	cur = ft_ln_lstnew(ln, cnt);
	if (!cur || !ln)
	{
		clear_ln_lst(head);
		return (0);
	}
	ft_ln_lstadd_back(head, cur);
	return (1);
}

void		fill_ln_lst(t_ln_lst **head, int fd)
{
	int			cnt;
	char		*ln;
	t_ln_lst	*cur;

	cnt = 1;
	while (get_next_line(fd, &ln) > 0)
	{
		if (!new_then_addback(head, ln, cnt))
			return ;
		cnt++;
	}
	if (!ft_strncmp(ln, "", ft_strlen(ln)))
	{
		free(ln);
		return ;
	}
	new_then_addback(head, ln, cnt);
}
