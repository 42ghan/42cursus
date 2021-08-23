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

static void	write_char(char *c, int *rep, int *prev, int *check)
{
	if (!(*c))
	{
		write(1, "\n\nSuccessful receipt!---------------\n\n", 39);
		*prev = 0;
		*check = 0;
	}
	else
		write(1, c, 1);
	*c = 0;
	*rep = 0;
}

static void	corrupt_byte(char *c, int *rep, int *prev, int *check)
{
	write(1, "\n\nSignals are mingled! Please send again\n\n", 41);
	*c = 0;
	*prev = 0;
	*check = 0;
	*rep = 0;
}

static void	send_check_signal(int sig, int c_pid, int *prev, int *check)
{
	*prev = sig;
	kill(c_pid, sig);
	*check = 1;
}

static void	srv_sig_handler(int sig, siginfo_t *info, void *ctxt)
{
	static char	c;
	static int	rep;
	static int	prev;
	static int	check;

	ctxt = NULL;
	if (!check)
		send_check_signal(sig, info->si_pid, &prev, &check);
	else
	{
		if (prev == sig)
		{
			c <<= 1;
			if (prev == SIGUSR1)
				c |= 0;
			else if (prev == SIGUSR2)
				c |= 1;
			check = 0;
			rep++;
			if (rep == 8)
				write_char(&c, &rep, &prev, &check);
		}
		else
			corrupt_byte(&c, &rep, &prev, &check);
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
	write(1, "server pid: ", 13);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	pid = NULL;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
