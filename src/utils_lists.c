/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:46:14 by ghan              #+#    #+#             */
/*   Updated: 2021/05/17 09:46:14 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_ln_lst	*ft_ln_lstnew(void *content, int num)
{
	t_ln_lst	*ret;

	ret = (t_ln_lst*)malloc(sizeof(t_ln_lst));
	if (!ret)
		return (NULL);
	ret->line = content;
	ret->line_num = num;
	ret->len = 0;
	if (content)
		ret->len = ft_strlen(content);
	ret->next = NULL;
	return (ret);
}

void		ft_ln_lstadd_back(t_ln_lst **lst, t_ln_lst *new)
{
	t_ln_lst	*last;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_ln_lst	*ft_ln_lstlast(t_ln_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void		clear_ln_lst(t_ln_lst **head)
{
	t_ln_lst	*cur;

	cur = *head;
	while (cur)
	{
		if (cur->line_num > 0)
		{
			free(cur->line);
			cur->line = NULL;
		}
		cur = cur->next;
		free(*head);
		*head = cur;
	}
	head = NULL;
}

t_ln_lst	*find_cur_line(t_mlx_bag *bag, int line_num)
{
	t_ln_lst	*cur;

	cur = *(bag->map);
	while (cur)
	{
		if (line_num == cur->line_num)
			return (cur);
		cur = cur->next;
	}
	return (*(bag->map));
}
