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

int			g_prev = 0;

static void	kill_error(void)
{
	write(1, "Wrong pid\n", 10);
	exit(1);
}

static void	check_receipt(int sig, siginfo_t *info, void *ctxt)
{
	ctxt = NULL;
	if (g_prev == sig)
	{
		kill(info->si_pid, sig);
		usleep(200);
	}
	// else
	// {
	// 	kill(info->si_pid, sig);
	// }
}

static void	send_signal(int pid, int *byte)
{
	int					i;
	struct sigaction	sa_c;

	sa_init(&sa_c, check_receipt);
	i = -1;
	while (++i < 8)
	{
		if (!(byte[i] % 2))
		{
			if (kill(pid, SIGUSR1) == -1)
				kill_error();				
			g_prev = SIGUSR1;
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				kill_error();
			g_prev = SIGUSR2;
		}
		sigaction(SIGUSR1, &sa_c, NULL);
		sigaction(SIGUSR2, &sa_c, NULL);
		usleep(100);
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
