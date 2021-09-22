/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:29:46 by ghan              #+#    #+#             */
/*   Updated: 2021/09/22 22:33:00 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h_ret;

	h_ret = (char *)h;
	if (*n == 0)
		return (h_ret);
	i = 0;
	while (*(h + i) && i < len)
	{
		if (*(h + i) == *n)
		{
			j = 1;
			while (i + j < len && *(h + i + j) == *(n + j) && *(n + j))
				j++;
			if (*(n + j) == 0)
				return (h_ret + i);
			else if (*(h + i + j) == 0)
				break ;
		}
		i++;
	}
	return (0);
}
