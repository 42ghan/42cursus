/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:42:03 by ghan              #+#    #+#             */
/*   Updated: 2021/06/27 20:42:03 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <stdio.h>

static void	srv_sig_handler(int sig)
{
	// static char	str[4];
	static char	c;
	static int	rep;
	// static int	rep_s;

	if (sig == SIGUSR1)
	{
		c <<= 1;
		c |= 0;
	}
	else if (sig == SIGUSR2)
	{
		c <<= 1;
		c |= 1;
	}
	rep++;
	if (rep == 8)
	{
		write(1, &c, 1);
		c = 0;
		rep = 0;
	}
}

int			main(void)
{
	struct sigaction	sa;
	char				*pid;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = srv_sig_handler;
	pid = ft_uitoa(getpid());
	if (!pid)
	{
		write(1, "pid itoa error\n", 15);
		return (1);
	}
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
