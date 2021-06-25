/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:11:57 by ghan              #+#    #+#             */
/*   Updated: 2021/06/25 19:11:58 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	key_left(int keycode, t_mlx_bag *bag)
{
	char	l;

	l = find_cur_line(bag, bag->p_y + 1)->line[bag->p_x - 1];
	if (keycode == 0 && l != '1')
	{
		(bag->p_x)--;
		(bag->moves)++;
		bag->moves_str = ft_uitoa(bag->moves);
		if (bag->moves_str)
		{
			write(1, bag->moves_str, ft_strlen(bag->moves_str));
			write(1, "\n", 1);
		}
		free(bag->moves_str);
		bag->moves_str = NULL;
	}
	return (keycode);
}

static int	key_right(int keycode, t_mlx_bag *bag)
{
	char	r;

	r = find_cur_line(bag, bag->p_y + 1)->line[bag->p_x + 1];
	if (keycode == 2 && r != '1')
	{
		(bag->p_x)++;
		(bag->moves)++;
		bag->moves_str = ft_uitoa(bag->moves);
		if (bag->moves_str)
		{
			write(1, bag->moves_str, ft_strlen(bag->moves_str));
			write(1, "\n", 1);
		}
		free(bag->moves_str);
		bag->moves_str = NULL;
	}
	return (keycode);
}

static int	key_up(int keycode, t_mlx_bag *bag)
{
	char	u;

	u = find_cur_line(bag, bag->p_y)->line[bag->p_x];
	if (keycode == 13 && u != '1')
	{
		(bag->p_y)--;
		(bag->moves)++;
		bag->moves_str = ft_uitoa(bag->moves);
		if (bag->moves_str)
		{
			write(1, bag->moves_str, ft_strlen(bag->moves_str));
			write(1, "\n", 1);
		}
		free(bag->moves_str);
		bag->moves_str = NULL;
	}
	return (keycode);
}

static int	key_down(int keycode, t_mlx_bag *bag)
{
	char	d;

	d = find_cur_line(bag, bag->p_y + 2)->line[bag->p_x];
	if (keycode == 1 && d != '1')
	{
		(bag->p_y)++;
		(bag->moves)++;
		bag->moves_str = ft_uitoa(bag->moves);
		if (bag->moves_str)
		{
			write(1, bag->moves_str, ft_strlen(bag->moves_str));
			write(1, "\n", 1);
		}
		free(bag->moves_str);
		bag->moves_str = NULL;
	}
	return (keycode);
}

int			key_press(int keycode, t_mlx_bag *bag)
{
	if (keycode == 0)
		key_left(keycode, bag);
	else if (keycode == 2)
		key_right(keycode, bag);
	else if (keycode == 13)
		key_up(keycode, bag);
	else if (keycode == 1)
		key_down(keycode, bag);
	else if (keycode == 53)
	{
		clear_ln_lst(bag->map);
		free(bag->moves_str);
		bag->moves_str = NULL;
		mlx_destroy_window(bag->mlx, bag->win);
		system("leaks so_long");
		exit(1);
	}
	return (keycode);
}
