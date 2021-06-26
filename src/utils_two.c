/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:37:54 by ghan              #+#    #+#             */
/*   Updated: 2021/06/25 18:37:55 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	unsigned int	i;

	ret = (unsigned char*)malloc(count * size);
	if (!ret)
		return (0);
	i = 0;
	while (i < count * size)
		*(unsigned char*)(ret + i++) = 0;
	return (ret);
}

char	*ft_uitoa(unsigned int n)
{
	int				cnt;
	char			*ret;
	unsigned int	n_cpy;

	n_cpy = n;
	cnt = 1;
	while (n_cpy / 10)
	{
		n_cpy /= 10;
		cnt++;
	}
	ret = ft_calloc((cnt + 1), 1);
	if (!ret)
		return (NULL);
	while (cnt)
	{
		ret[cnt - 1] = "0123456789"[n % 10];
		n /= 10;
		cnt--;
	}
	return (ret);
}

int		close_window(t_mlx_bag *bag)
{
	clear_ln_lst(bag->map);
	free(bag->moves_str);
	bag->moves_str = NULL;
	mlx_destroy_window(bag->mlx, bag->win);
	exit(1);
	return (0);
}

void	str_malloc_error(t_mlx_bag *bag)
{
	clear_ln_lst(bag->map);
	mlx_destroy_window(bag->mlx, bag->win);
	perror("Error\nDisplay error");
	exit(1);
}

int		collect_count(t_ln_lst *cur)
{
	int		cnt;
	int		i;

	cnt = 0;
	while (cur)
	{
		i = 0;
		while (cur->line[i])
		{
			if (cur->line[i] == 'C')
				cnt++;
			i++;
		}
		cur = cur->next;
	}
	return (cnt);
}
