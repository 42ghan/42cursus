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

static int	display_window(t_ln_lst **head, int w, int h)
{
	void		*mlx;
	void		*m_win;
	t_mlx_bag	bag;

	mlx = mlx_init();
	if (!mlx)
		return (0);
	m_win = mlx_new_window(mlx, w * 64, h * 64, "so_long");
	if (!m_win || !mlx_bag_init(mlx, m_win, head, &bag))
	{
		free(mlx);
		mlx = NULL;
		free(m_win);
		m_win = NULL;
		return (0);
	}
	mlx_loop_hook(mlx, put_tiles, &bag);
	mlx_hook(m_win, 2, 1L << 0, key_press, &bag);
	mlx_hook(m_win, 17, 0, close_window, &bag);
	mlx_loop(mlx);
	return (1);
}

static int	map_size_check(t_ln_lst **head, int *width, int *height)
{
	*width = (*head)->next->len;
	*height = ft_ln_lstlast(*head)->line_num;
	if (*width > 40 || *height > 20 || *width < 3 || *height < 3)
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

int			main(int argc, char *argv[])
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
	if (!display_window(&head, width, height))
	{
		perror("Error\nDisplay error");
		return (1);
	}
	clear_ln_lst(&head);
	return (0);
}
