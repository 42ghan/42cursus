/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:41:40 by ghan              #+#    #+#             */
/*   Updated: 2021/06/27 20:41:40 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <stdio.h>

char	*g_str = NULL;

static void	client_signal_handler(int	signal)
{
	write(1, g_str, ft_strlen(g_str));
	printf("%d\n", signal);
}

int			main(int argc, char *argv[])
{
	g_str = NULL;
	if (argc != 3 || ft_atoi(argv[1]) < 0)
	{
		write(1, "Argument Error\n", 15);
		return (1);
	}
	g_str = argv[2];
	signal(SIGUSR1, client_signal_handler);
	kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}
