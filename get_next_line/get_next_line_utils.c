/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:46:14 by ghan              #+#    #+#             */
/*   Updated: 2021/11/21 01:06:30 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

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

t_lst	*ft_lstnew(void *content, int fd)
{
	t_lst	*ret;

	ret = (t_lst *)malloc(sizeof(t_lst));
	if (ret == NULL)
		return (0);
	ret->backup = content;
	ret->fd = fd;
	ret->next = NULL;
	return (ret);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	if (len > n)
		len = n;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	m_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strndup("", 1));
	m_len = len;
	if (ft_strlen(s) - start <= len)
		m_len = ft_strlen(s) - start;
	ret = (char *)malloc(m_len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s[start + i] && i < m_len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	k;

	if (!s1 || !s2)
		return (0);
	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
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
	ret[i + k] = '\0';
	return (ret);
}
