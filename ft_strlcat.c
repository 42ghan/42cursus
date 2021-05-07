/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:14:06 by ghan              #+#    #+#             */
/*   Updated: 2021/05/03 19:14:10 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int cnt;
	unsigned int cnt2;
	unsigned int i;

	cnt = 0;
	while (dst[cnt])
		cnt++;
	cnt2 = 0;
	while (src[cnt2])
		cnt2++;
	if (size == 0)
		return (cnt2);
	i = 0;
	while (src[i] && (i + cnt + 1) < size)
	{
		dst[cnt + i] = src[i];
		i++;
	}
	dst[cnt + i] = 0;
	if (size < cnt)
		return (cnt2 + size);
	else
		return (cnt + cnt2);
}
