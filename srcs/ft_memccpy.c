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
	int i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(src + i) == c)
			return (dst + i + 1);
		*(unsigned char*)(dst + i) = *(unsigned char*)(src + i++);
	}
	return (0);
}
