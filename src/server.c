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

static void	server_signal_handler(int	signal)
{
	printf("%d\n", signal);
}

int		main(void)
{
	char	*pid;

	pid = ft_uitoa(getpid());
	if (!pid)
	{
		write(1, "pid itoa error\n", 15);
		return (1);
	}
	write(1, pid, ft_strlen(pid));
	signal(SIGUSR1, server_signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
