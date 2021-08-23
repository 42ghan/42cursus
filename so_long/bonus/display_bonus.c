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

void		patrol_positions(t_ln_lst *cur)
{
	int		x;
	int		y;

	y = 0;
	while (cur)
	{
		x = 0;
		while (cur->line[x])
		{
			if (x % 7 == 2 && y % 5 == 3 && cur->line[x] == '0')
				cur->line[x] = 'D';
			x++;
		}
		cur = cur->next;
		y++;
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
			image_to_window(bag, (map->line)[x], x * 64, y * 64);
			player_mes_to_win(bag);
			player_collect_cond(bag, map, x, y);
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
