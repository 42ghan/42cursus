/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:26:27 by ghan              #+#    #+#             */
/*   Updated: 2021/05/03 17:27:02 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*src_cpy;

	src_cpy = (unsigned char*)src;
	i = 0;
	while (i < n && *(unsigned char*)src_cpy != (unsigned char)c)
	{
		*(unsigned char*)dst = *(unsigned char*)src_cpy;
		dst++;
		src_cpy++;
		i++;
	}
	if (i != n)
	{
		*(unsigned char*)dst = *(unsigned char*)src_cpy;
		return (dst + 1);
	}
	return (0);
}
