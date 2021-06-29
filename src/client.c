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

static void	send_signal(int pid, int *byte)
{
	int		status;
	int		i;

	i = 0;
	while (i < 8)
	{
		if (!(byte[i] % 2))
			status = kill(pid, SIGUSR1);
		else
			status = kill(pid, SIGUSR2);
		if (status == -1)
		{
			write(1, "Wrong pid\n", 10);
			exit(1);
		}
		usleep(100);
		i++;
	}
}

int			main(int argc, char *argv[])
{
	int		i;
	int		bit;
	int		byte[8];
	unsigned char	c;

	if (argc != 3 || ft_atoi(argv[1]) < 0)
	{
		write(1, "Argument Error\n", 15);
		return (1);
	}
	i = 0;
	while (argv[2][i])
	{
		c = (unsigned char)argv[2][i];
		bit = 7;
		while (bit >= 0)
		{
			byte[bit--] = c % 2;
			c /= 2;
		}
		send_signal(ft_atoi(argv[1]), byte);
		i++;
	}
	return (0);
}
