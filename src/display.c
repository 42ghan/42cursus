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

void		mlx_bag_init(void *mlx, void *win, t_ln_lst **line, t_mlx_bag *bag)
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
	bag->col_two = mlx_xpm_file_to_image(mlx, "texture/col2.xpm", &w, &h);
	bag->start = mlx_xpm_file_to_image(mlx, "texture/start.xpm", &w, &h);
	bag->p_img = mlx_xpm_file_to_image(mlx, "texture/player.xpm", &w, &h);
	bag->first = 0;
	bag->time = 1;
	bag->moves = 0;
	bag->moves_str = NULL;
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
		if (b->time < 7)
			mlx_put_image_to_window(b->mlx, b->win, b->col, x, y);
		else
			mlx_put_image_to_window(b->mlx, b->win, b->col_two, x, y);
	}
	mlx_put_image_to_window(b->mlx, b->win, b->p_img, b->p_x * 64,
	b->p_y * 64);
	mlx_string_put(b->mlx, b->win, 18, 24, 0x00ff0000, "MOVES : ");
	b->moves_str = ft_uitoa(b->moves);
	if (!b->moves_str)
		str_malloc_error(b);
	mlx_string_put(b->mlx, b->win, 70, 24, 0x00ff0000, b->moves_str);
	free(b->moves_str);
	b->moves_str = NULL;
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
		map->line[x] = '0';
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
			image_to_window(bag, (map->line)[x], x * 64 , y * 64);
			x++;
		}
		map = map->next;
		y++;
	}
	(bag->time)++;
	if (bag->time == 14)
		bag->time = 0;
	return (0);
}
