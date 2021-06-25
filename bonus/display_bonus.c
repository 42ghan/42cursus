/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:41:15 by ghan              #+#    #+#             */
/*   Updated: 2021/06/25 14:41:17 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	collect_count(t_ln_lst *cur)
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
	bag->col_two = mlx_xpm_file_to_image(mlx, "texture/col_two.xpm", &w, &h);
	bag->patrol = mlx_xpm_file_to_image(mlx, "texture/patrol.xpm", &w, &h);
	bag->pat_two = mlx_xpm_file_to_image(mlx, "texture/pat_two.xpm", &w, &h);
	bag->start = mlx_xpm_file_to_image(mlx, "texture/start.xpm", &w, &h);
	bag->p_img = mlx_xpm_file_to_image(mlx, "texture/player.xpm", &w, &h);
	bag->col_num = collect_count((*line)->next);
	bag->first = 0;
	bag->time = 1;
	bag->moves = 0;
	bag->result = 0;
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
	else if (c == 'D')
	{
		mlx_put_image_to_window(b->mlx, b->win, b->empty, x, y);
		if (b->time < 7)
			mlx_put_image_to_window(b->mlx, b->win, b->patrol, x, y);
		else
			mlx_put_image_to_window(b->mlx, b->win, b->pat_two, x, y);
	}
}

static void	player_mes_to_win(t_mlx_bag *b)
{
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

static void	player_collect_cond(t_mlx_bag *b, t_ln_lst *map, int x, int y)
{
	if (!b->first && (map->line)[x] == 'P')
	{
		b->p_x = x;
		b->p_y = y;
		b->first = 1;
	}
	if (map->line[x] == 'C' && b->p_x == x && b->p_y == y)
	{
		map->line[x] = '0';
		(b->col_num)--;
	}
	if (map->line[x] == 'E' && b->p_x == x && b->p_y == y && b->col_num == 0)
	{
		mlx_string_put(b->mlx, b->win, 18, 48, 0x00ff0000,
		"Congratulations :D");
		mlx_string_put(b->mlx, b->win, 18, 72, 0x00ff0000,
		"You are the hero!");
		b->result = 1;
	}
	if (map->line[x] == 'D' && b->p_x == x && b->p_y == y)
	{
		mlx_string_put(b->mlx, b->win, 18, 48, 0x00ff0000,
		"LOL! You are dead!");
		b->result = 1;
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
			image_to_window(bag, (map->line)[x], x * 64 , y * 64);
			player_mes_to_win(bag);
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
