/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:33:13 by ghan              #+#    #+#             */
/*   Updated: 2021/05/14 15:15:14 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	size_t			m_len;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strndup("", 1));
	m_len = (ft_strlen(s) - start) > len ? len : (ft_strlen(s) - start);
	if (!(ret = (char*)malloc(m_len + 1)))
		return (0);
	i = 0;
	while (s[start + i] && i < m_len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	unsigned int	i;
	unsigned int	k;

	if (!s1 || !s2)
		return (0);
	if (!(ret = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	ret[0] = 0;
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		ret[i + k] = s2[k];
		k++;
	}
	ret[i + k] = 0;
	return (ret);
}

void			ft_lstdelone(t_list *lst, t_list **prev, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	while ((*prev)->next->fd != lst->fd)
		*prev = (*prev)->next;
	(*prev)->next = lst->next;
	del(lst->backup);
	del(lst);
}

t_list			*ft_lstnew(void *content, int fd)
{
	t_list	*ret;

	if (!(ret = (t_list*)malloc(sizeof(t_list))))
		return (0);
	ret->backup = content;
	ret->fd = fd;
	ret->next = 0;
	return (ret);
}

void			ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

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
