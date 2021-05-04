/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:36:44 by ghan              #+#    #+#             */
/*   Updated: 2021/05/03 17:36:46 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned int len)
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
