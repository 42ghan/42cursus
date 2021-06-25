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
