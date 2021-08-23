/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:54:37 by ghan              #+#    #+#             */
/*   Updated: 2021/05/03 17:54:38 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n && *(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i))
		i++;
	if (i == n)
		return (0);
	return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
}
