/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:04:31 by ghan              #+#    #+#             */
/*   Updated: 2021/06/26 16:04:32 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (!bag->wall || !bag->empty || !bag->exit || !bag->col || !bag->col_two ||
	!bag->patrol || !bag->pat_two || !bag->start || !bag->p_img)
		return (0);
	return (1);
}

void		image_to_window(t_mlx_bag *b, char c, int x, int y)
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
