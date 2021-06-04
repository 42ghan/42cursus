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

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int i;

	if (len == 0)
		return (dst);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i++;
		}
	}
	else if (dst > src)
	{
		len--;
		while (len > 0)
		{
			*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
			len--;
		}
		*(unsigned char*)dst = *(unsigned char*)src;
	}
	return (dst);
}

void		*ft_memset(void *s, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
		*(unsigned char*)(s + i++) = (unsigned char)c;
	return (s);
}

void		*ft_calloc(size_t count, size_t size)
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
