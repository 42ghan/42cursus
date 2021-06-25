/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 19:11:57 by ghan              #+#    #+#             */
/*   Updated: 2021/06/25 19:11:58 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			write(1, "No. of movements: ", 18);
			write(1, bag->moves_str, ft_strlen(bag->moves_str));
			write(1, "\n", 1);
		}
		else
			str_malloc_error(bag);
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
			write(1, "No. of movements: ", 18);
			write(1, bag->moves_str, ft_strlen(bag->moves_str));
			write(1, "\n", 1);
		}
		else
			str_malloc_error(bag);
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
			write(1, "No. of movements: ", 18);
			write(1, bag->moves_str, ft_strlen(bag->moves_str));
			write(1, "\n", 1);
		}
		else
			str_malloc_error(bag);
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
			write(1, "No. of movements: ", 18);
			write(1, bag->moves_str, ft_strlen(bag->moves_str));
			write(1, "\n", 1);
		}
		else
			str_malloc_error(bag);
		free(bag->moves_str);
		bag->moves_str = NULL;
	}
	return (keycode);
}

int			key_press(int keycode, t_mlx_bag *bag)
{
	if (keycode == 0 && !bag->result)
		key_left(keycode, bag);
	else if (keycode == 2 && !bag->result)
		key_right(keycode, bag);
	else if (keycode == 13 && !bag->result)
		key_up(keycode, bag);
	else if (keycode == 1 && !bag->result)
		key_down(keycode, bag);
	else if (keycode == 53)
		close_window(bag);
	return (keycode);
}
