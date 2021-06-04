/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:10:48 by ghan              #+#    #+#             */
/*   Updated: 2021/06/04 17:10:48 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_strlen(const char *s)
{
	unsigned int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char		*ft_strndup(const char *s1, size_t n)
{
	char			*ret;
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (s1[len])
		len++;
	if (len > n)
		len = n;
	ret = (char*)ft_calloc(len + 1, 1);
	if (!ret)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	return (ret);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	size_t			m_len;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strndup("", 1));
	m_len = len;
	if ((ft_strlen(s) - start) < len)
		m_len = ft_strlen(s) - start;
	ret = (char*)ft_calloc(m_len + 1, 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s[start + i] && i < m_len)
	{
		ret[i] = s[start + i];
		i++;
	}
	return (ret);
}

void		flist_add_back(t_flist **lst, t_flist *new)
{
	t_flist	*last;

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

t_flist		*flist_init(void)
{
	t_flist	*ret;

	ret = (t_flist*)malloc(sizeof(t_flist));
	if (!ret)
		return (NULL);
	ret->start = 0;
	ret->end = 0;
	ret->ast_cnt = 0;
	ret->align = 0;
	ret->zero = 0;
	ret->form = 0;
	ret->width = 0;
	ret->prec = 0;
	ret->flag = NULL;
	ret->prnt = NULL;
	ret->next = NULL;
	return (ret);
}
