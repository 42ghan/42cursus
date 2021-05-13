/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:05:18 by ghan              #+#    #+#             */
/*   Updated: 2021/05/10 18:05:19 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char			*ret;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s1);
	if (len > n)
		len = n;
	if (!(ret = (char*)malloc(len + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int dst_len;
	unsigned int src_len;
	unsigned int i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size < dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] && (i + dst_len + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (!s1 || !s2)
		return (0);
	if (!(ret = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	ret[0] = 0;
	ft_strlcat(ret, s1, ft_strlen(s1) + 1);
	ft_strlcat(ret, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (ret);
}
