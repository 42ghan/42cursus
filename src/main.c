/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:16:41 by ghan              #+#    #+#             */
/*   Updated: 2021/06/21 21:16:43 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	imgs_init(void *mlx, void *win, t_img_bag *bag)
{
	int		w;
	int		h;

	bag->mlx = mlx;
	bag->win = win;
	bag->wall = mlx_xpm_file_to_image(mlx, "texture/wall.xpm", &w, &h);
	bag->empty = mlx_xpm_file_to_image(mlx, "texture/empty.xpm", &w, &h);
	bag->exit = mlx_xpm_file_to_image(mlx, "texture/exit.xpm", &w, &h);
	bag->collect = mlx_xpm_file_to_image(mlx, "texture/collect.xpm", &w, &h);
	bag->start = mlx_xpm_file_to_image(mlx, "texture/start.xpm", &w, &h);
	bag->player = mlx_xpm_file_to_image(mlx, "texture/player.xpm", &w, &h);
}

static void	image_to_window(t_img_bag bag, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(bag.mlx, bag.win, bag.wall, x * 64, y * 64);
	else if (c == '0')
		mlx_put_image_to_window(bag.mlx, bag.win, bag.empty, x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(bag.mlx, bag.win, bag.exit, x * 64, y * 64);
	else if (c == 'P')
	{
		mlx_put_image_to_window(bag.mlx, bag.win, bag.start, x * 64, y * 64);
		mlx_put_image_to_window(bag.mlx, bag.win, bag.player, x * 64, y * 64);
	}
	else if (c == 'C')
		mlx_put_image_to_window(bag.mlx, bag.win, bag.collect, x * 64, y * 64);
}

static void	put_tiles(void *mlx, void *win, t_ln_lst *cur)
{
	int			x;
	int			y;
	t_img_bag	bag;

	imgs_init(mlx, win, &bag);
	y = 0;
	while (cur)
	{
		x = 0;
		while ((cur->line)[x])
		{
			image_to_window(bag, (cur->line)[x], x, y);
			x++;
		}
		cur = cur->next;
		y++;
	}
}

/* TODO - create display with mlx */
static int	display_window(t_ln_lst *head, int w, int h)
{
	void	*mlx;
	void	*m_win;

	mlx = mlx_init();
	m_win = mlx_new_window(mlx, w * 64, h * 64, "so_long");
	put_tiles(mlx, m_win, head->next);
	mlx_loop(mlx);
	return (1);
}

static int	map_size_check(t_ln_lst **head, int *width, int *height)
{
	*width = (*head)->next->len;
	*height = ft_ln_lstlast(*head)->line_num;
	if (*width > 24 || *height > 18 || *width < 3 || *height < 3)
	{
		clear_ln_lst(head);
		return (0);
	}
	return (1);
}

static void	open_parse_ber(char *ber, t_ln_lst **head)
{
	int			fd;

	fd = open(ber, O_RDONLY);
	if (fd < 0 || ft_strncmp((ber + ft_strlen(ber) - 4), ".ber", 4))
	{
		perror("Error\nFile open error");
		exit(1);
	}
	fill_ln_lst(head, fd);
	if (!check_map_validity(head) && *head)
		clear_ln_lst(head);
	close(fd);
}

int			main(int argc, char* argv[])
{
	t_ln_lst	*head;
	int			width;
	int			height;

	if (argc != 2)
	{
		perror("Error\nWrong number of args");
		return (1);
	}
	head = ft_ln_lstnew(NULL, 0);
	if (head)
		open_parse_ber(argv[1], &head);
	if (!head || !map_size_check(&head, &width, &height))
	{
		perror("Error\nInvalid map");
		return (1);
	}
	if (!display_window(head, width, height))
	{
		perror("Error\nDisplay error");
		return (1);
	}
	clear_ln_lst(&head);
	return (0);
}
