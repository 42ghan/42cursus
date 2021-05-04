/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:19:50 by ghan              #+#    #+#             */
/*   Updated: 2021/05/03 17:19:54 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
		i++;
	}
	return (dst);
}
