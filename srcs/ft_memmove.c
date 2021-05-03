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
	int i;

	if (dst < src)
	{
		i = len - 1;
		while (i >= 0)
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i--);
	}
	else if (dst > src)
	{
		i = 0;
		while (i < len)
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i++);
	}
	return (dst);
}
