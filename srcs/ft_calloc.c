/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:12:04 by ghan              #+#    #+#             */
/*   Updated: 2021/05/04 11:12:05 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void			*ret;
	unsigned int	i;

	ret = (unsigned char*)malloc(count * size);
	i = 0;
	while (i < count * size)
		*(unsigned char*)(ret + i++) = 0;
	return (ret);
}
