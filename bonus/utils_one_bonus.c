/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:34:09 by ghan              #+#    #+#             */
/*   Updated: 2021/06/23 17:34:10 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t		ft_strlen(const char *s)
{
	unsigned int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char*)s1;
	s2_cpy = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while ((*s1_cpy == *s2_cpy) && n > 1 && *s1_cpy)
	{
		s1_cpy++;
		s2_cpy++;
		n--;
	}
	return (*s1_cpy - *s2_cpy);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	unsigned int	i;

	ret = (unsigned char*)malloc(count * size);
	if (!ret)
		return (0);
	i = 0;
	while (i < count * size)
		*(unsigned char*)(ret + i++) = 0;
	return (ret);
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

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	size_t			m_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strndup("", 1));
	m_len = (ft_strlen(s) - start) > len ? len : (ft_strlen(s) - start);
	ret = (char*)ft_calloc((m_len + 1), 1);
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	unsigned int	i;
	unsigned int	k;

	if (!s1 || !s2)
		return (NULL);
	ret = (char*)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), 1);
	if (!ret)
		return (NULL);
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
	return (ret);
}
