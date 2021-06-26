/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:41:15 by ghan              #+#    #+#             */
/*   Updated: 2021/06/25 14:41:17 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_images(t_mlx_bag *bag)
{
	if (!bag->wall || !bag->empty || !bag->exit || !bag->col ||
	!bag->start || !bag->p_img)
	{
		if (bag->wall)
			mlx_destroy_image(bag->mlx, bag->wall);
		if (bag->empty)
			mlx_destroy_image(bag->mlx, bag->empty);
		if (bag->col)
			mlx_destroy_image(bag->mlx, bag->col);
		if (bag->start)
			mlx_destroy_image(bag->mlx, bag->start);
		if (bag->exit)
			mlx_destroy_image(bag->mlx, bag->exit);
		if (bag->p_img)
			mlx_destroy_image(bag->mlx, bag->p_img);
		return (0);
	}
	return (1);
}

int			mlx_bag_init(void *mlx, void *win, t_ln_lst **line, t_mlx_bag *bag)
{
	int		w;
	int		h;

	bag->map = line;
	bag->mlx = mlx;
	bag->win = win;
	bag->wall = mlx_xpm_file_to_image(mlx, "texture/wall.xpm", &w, &h);
	bag->empty = mlx_xpm_file_to_image(mlx, "texture/empty.xpm", &w, &h);
	bag->exit = mlx_xpm_file_to_image(mlx, "texture/exit.xpm", &w, &h);
	bag->col = mlx_xpm_file_to_image(mlx, "texture/col.xpm", &w, &h);
	bag->start = mlx_xpm_file_to_image(mlx, "texture/start.xpm", &w, &h);
	bag->p_img = mlx_xpm_file_to_image(mlx, "texture/player.xpm", &w, &h);
	bag->col_num = collect_count((*line)->next);
	bag->first = 0;
	bag->moves = 0;
	bag->result = 0;
	bag->moves_str = NULL;
	if (!check_images(bag))
		return (0);
	return (1);
}

static void	image_to_window(t_mlx_bag *b, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(b->mlx, b->win, b->wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(b->mlx, b->win, b->empty, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(b->mlx, b->win, b->exit, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(b->mlx, b->win, b->start, x, y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(b->mlx, b->win, b->empty, x, y);
		mlx_put_image_to_window(b->mlx, b->win, b->col, x, y);
	}
	mlx_put_image_to_window(b->mlx, b->win, b->p_img, b->p_x * 64,
	b->p_y * 64);
}

static void	player_collect_cond(t_mlx_bag *bag, t_ln_lst *map, int x, int y)
{
	if (!bag->first && (map->line)[x] == 'P')
	{
		bag->p_x = x;
		bag->p_y = y;
		bag->first = 1;
	}
	if (map->line[x] == 'C' && bag->p_x == x && bag->p_y == y)
	{
		map->line[x] = '0';
		(bag->col_num)--;
	}
	if (map->line[x] == 'E' && bag->p_x == x && bag->p_y == y &&
	bag->col_num == 0)
	{
		mlx_string_put(bag->mlx, bag->win, 18, 48, 0x00ff0000,
		"Congratulations :D");
		mlx_string_put(bag->mlx, bag->win, 18, 72, 0x00ff0000,
		"You are today's hero!");
		bag->result = 1;
	}
}

int			put_tiles(t_mlx_bag *bag)
{
	int			x;
	int			y;
	t_ln_lst	*map;

	y = 0;
	map = *(bag->map);
	map = map->next;
	while (map)
	{
		x = 0;
		while ((map->line)[x])
		{
			player_collect_cond(bag, map, x, y);
			image_to_window(bag, (map->line)[x], x * 64, y * 64);
			x++;
		}
		map = map->next;
		y++;
	}
	return (0);
}
