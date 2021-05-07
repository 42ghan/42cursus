/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:57:57 by ghan              #+#    #+#             */
/*   Updated: 2021/05/04 15:57:59 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	find_start(char *s, char *set)
{
	unsigned int	start;

	start = 0;
	while (s[start])
	{
		if (!ft_strchr(set, s[start]))
			break ;
		start++;
	}
	return (start);
}

unsigned int	find_end(char *s, char *set, unsigned int start)
{
	unsigned int	end;

	end = ft_strlen(s) - 1;
	while (end > start)
	{
		if (!ft_strchr(set, s[end]))
			break ;
		end--;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*ret;
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;

	if (!s1)
		return (0);
	if (!s1[0])
		return (ft_calloc(1, 1));
	start = find_start((char*)s1, (char*)set);
	end = find_end((char*)s1, (char*)set, start);
	if (!(ret = (char*)malloc(end - start + 2)))
		return (0);
	i = 0;
	while (i < end - start + 1)
	{
		ret[i] = s1[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
