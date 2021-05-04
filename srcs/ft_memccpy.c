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

void	*ft_memccpy(void *dst, const void *src, int c, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && *(unsigned char*)src != c)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		dst++;
		src++;
		i++;
	}
	if (i != n)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		return (dst + 1);
	}
	return (0);
}
