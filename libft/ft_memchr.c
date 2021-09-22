/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:47:48 by ghan              #+#    #+#             */
/*   Updated: 2021/09/22 22:40:52 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*ret;

	ret = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)ret == (unsigned char)c)
			return (ret);
		ret++;
		i++;
	}
	return (0);
}
