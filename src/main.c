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

/* TODO - create display with mlx */
static display_window(t_ln_lst *head)
{

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

	if (argc != 2)
	{
		perror("Error\nWrong number of args");
		return (1);
	}
	head = ft_ln_lstnew(NULL, 0);
	if (head)
		open_parse_ber(argv[1], &head);
	if (!head)
	{
		perror("Error\nInvalid map");
		return (1);
	}
	display_window(head);
	clear_ln_lst(&head);
	return (0);
}
