/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:58:09 by ghan              #+#    #+#             */
/*   Updated: 2021/05/04 15:58:10 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	find_del_idx(char *s, char c, unsigned int idx)
{
	while (s[idx])
	{
		if (s[idx] == c)
			return (idx);
		idx++;
	}
	return (idx);
}

static void			clear_arr(char **ret, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (j < i)
	{
		free(ret[j]);
		free(ret);
		j++;
	}
}

static void			fill(char *d, char *s, unsigned int start, unsigned int end)
{
	unsigned int	i;

	i = 0;
	while (start < end)
	{
		d[i] = s[start];
		start++;
		i++;
	}
	d[i] = 0;
}

static void			assign_arr(char **ret, char *s, char c, unsigned int cnt)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

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
			if (!(ret[i] = (char*)malloc(k - j + 1)))
			{
				clear_arr(ret, i);
				return ;
			}
			!i && *s != c ? fill(ret[i++], s, j, k) : fill(ret[i++], s, ++j, k);
			j = k;
		}
	}
}

char				**ft_split(char const *s, char c)
{
	char			**ret;
	char			*s_cpy;
	unsigned int	cnt;
	unsigned int	i;

	if (!s)
		return (0);
	s_cpy = (char*)s;
	cnt = 0;
	if (s[0])
	{
		cnt = s[0] == c ? 0 : 1;
		i = 0;
		while (s[++i])
		{
			if (s[i - 1] == c && s[i] != c)
				cnt++;
		}
	}
	if (!(ret = (char**)malloc(sizeof(char*) * (cnt + 1))))
		return (0);
	assign_arr(ret, s_cpy, c, cnt);
	if (ret)
		ret[cnt] = 0;
	return (ret);
}
