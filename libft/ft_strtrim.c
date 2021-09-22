/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:57:57 by ghan              #+#    #+#             */
/*   Updated: 2021/09/22 22:34:39 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find_start(char *s, char *set)
{
	size_t	start;

	start = 0;
	while (s[start])
	{
		if (!ft_strchr(set, s[start]))
			break ;
		start++;
	}
	return (start);
}

size_t	find_end(char *s, char *set, size_t start)
{
	size_t	end;

	end = ft_strlen(s) - 1;
	while (end > start)
	{
		if (!ft_strchr(set, s[end]))
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (0);
	if (!s1[0])
		return (ft_calloc(1, 1));
	start = find_start((char *)s1, (char *)set);
	end = find_end((char *)s1, (char *)set, start);
	ret = (char *)ft_calloc(end - start + 2, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		ret[i] = s1[start + i];
		i++;
	}
	return (ret);
}
