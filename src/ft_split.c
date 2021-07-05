/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:18:24 by ghan              #+#    #+#             */
/*   Updated: 2021/07/05 13:18:25 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_del_idx(char *s, char c, int idx)
{
	while (s[idx])
	{
		if (s[idx] == c)
			return (idx);
		idx++;
	}
	return (idx);
}

static void	clear_arr(char **ret, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(ret[j]);
		ret[j] = NULL;
		j++;
	}
	free(ret);
	ret = NULL;
}

static void	fill(char *d, char *s, int start, int end)
{
	if (start || s[start] == s[end])
		start++;
	while (start < end)
	{
		*d = s[start];
		start++;
		d++;
	}
}

static void	assign_arr(char **ret, char *s, char c, unsigned int cnt)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	while (i < cnt)
	{
		end = find_del_idx(s, c, start + 1);
		if (s[start] == c && s[start + 1] == c)
			end = find_del_idx(s, c, ++start + 1);
		else
		{
			ret[i] = (char *)ft_calloc(end - start + 1, 1);
			if (!(ret[i]))
			{
				clear_arr(ret, i);
				return ;
			}
			fill(ret[i++], s, start, end);
			start = end;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		cnt;
	int		i;

	if (!s)
		return (0);
	cnt = 0;
	if (s[0])
	{
		cnt = 1;
		if (s[0] == c)
			cnt = 0;
		i = 0;
		while (s[++i])
		{
			if (s[i - 1] == c && s[i] != c)
				cnt++;
		}
	}
	ret = (char **)ft_calloc((cnt + 1), sizeof(char *));
	if (!ret)
		return (0);
	assign_arr(ret, (char *)s, c, cnt);
	return (ret);
}
