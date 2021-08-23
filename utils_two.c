/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:17:40 by ghan              #+#    #+#             */
/*   Updated: 2021/05/20 12:17:40 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	ret = (char*)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (ret + i);
		i++;
	}
	if (s[i] == (char)c)
		return (ret + i);
	return (0);
}

char	*strncpy_no_null(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		*(unsigned char*)(s + i++) = (unsigned char)c;
	return (s);
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
