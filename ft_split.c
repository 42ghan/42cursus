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
		j++;
	}
}

static void			fill_str(char *d, char *s, unsigned int i, unsigned int end)
{
	unsigned int	j;

	j = 0;
	if (i == 1)
		i = 0;
	while (i < end)
	{
		d[j] = s[i];
		i++;
		j++;
	}
	d[j] = 0;
}

static void			assign_arr(char **ret, char *s, char c, unsigned int cnt)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	start = 0;
	while (i < cnt)
	{
		end = find_del_idx(s, c, start + 1);
		if (s[start] == c && s[start + 1] == c)
		{
			start = end;
			end = find_del_idx(s, c, start + 1);
		}
		else
		{
			if (!(ret[i] = (char*)malloc(end - start + 1)))
			{
				clear_arr(ret, i);
				break ;
			}
			fill_str(ret[i++], s, start + 1, end);
			start = end;
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
		if (s[0] != c)
			cnt = 1;
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
	ret[cnt] = 0;
	return (ret);
}
