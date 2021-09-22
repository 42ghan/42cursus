/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:58:09 by ghan              #+#    #+#             */
/*   Updated: 2021/09/23 00:29:01 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_del_idx(char *s, char c, size_t idx)
{
	while (s[idx])
	{
		if (s[idx] == c)
			return (idx);
		idx++;
	}
	return (idx);
}

static void	clear_arr(char **ret, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(ret[j++]);
		free(ret);
	}
}

static int	alloc_str(char **ret, int i, int len)
{
	ret[i] = (char *)ft_calloc(len, sizeof(char));
	if (!ret[i])
	{
		clear_arr(ret, i);
		return (0);
	}
	return (1);
}

static void	assign_arr(char **ret, char *s, char c, size_t cnt)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < cnt)
	{
		k = find_del_idx(s, c, j + 1);
		if (s[j] == c && s[j + 1] == c)
		{
			j = k;
			k = find_del_idx(s, c, j + 1);
		}
		else
		{
			if (!alloc_str(ret, i, k - j + 1))
				return ;
			if (!i && *s != c)
				ft_strlcpy(ret[i++], s + j, k - j + 1);
			else
				ft_strlcpy(ret[i++], s + j + 1, k - j);
			j = k;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	cnt;
	size_t	i;

	if (!s)
		return (0);
	cnt = 0;
	if (s[0])
	{
		cnt = 1;
		if (s[0] == c)
			cnt = 0;
		i = 0;
		while (ft_strlen(s) > 1 && s[++i])
		{
			if (s[i - 1] == c && s[i] != c)
				cnt++;
		}
	}
	ret = (char **)ft_calloc(cnt + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	assign_arr(ret, (char *)s, c, cnt);
	return (ret);
}
