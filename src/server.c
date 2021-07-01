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

int			g_check = 0;

static void	srv_sig_handler(int sig, siginfo_t *info, void *ctxt)
{
	static char	c;
	static int	rep;
	static int	prev;

	ctxt = NULL;
	if (!g_check)
	{
		prev = sig;
		kill(info->si_pid, sig);
		g_check = 1;
	}
	else
	{
		if (prev == sig)
		{
			c <<= 1;
			if (prev == SIGUSR1)
				c |= 0;
			else if (prev == SIGUSR2)
				c |= 1;
			g_check = 0;
			rep++;
		}
	}
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

	sa_init(&sa, srv_sig_handler);
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
