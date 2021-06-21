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

int		main(int argc, char* argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		perror("Can't open the given .ber file");
	return (0);
}