/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:26:29 by ghan              #+#    #+#             */
/*   Updated: 2021/05/03 20:26:31 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_l;

	src_l = 0;
	while (src[src_l])
		src_l++;
	if (size == 0)
		return (src_l);
	i = 0;
	while (src[i] && i + 1 < size)
		dst[i] = src[i++];
	dst[i] = 0;
	return (src_l);
}
