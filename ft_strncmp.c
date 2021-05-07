/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:47:17 by ghan              #+#    #+#             */
/*   Updated: 2021/05/03 19:47:19 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char*)s1;
	s2_cpy = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while ((*s1_cpy == *s2_cpy) && n > 1 && *s1_cpy && *s2_cpy)
	{
		s1_cpy++;
		s2_cpy++;
		n--;
	}
	return (*s1_cpy - *s2_cpy);
}
