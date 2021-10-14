/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:26:42 by ghan              #+#    #+#             */
/*   Updated: 2021/10/14 16:30:57 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((long)now.tv_sec * 1000000 + (long)now.tv_usec);
}

long	time_cal(long start_t)
{
	return ((get_now() - start_t) / 1000);
}

int	ft_usleep(long interval)
{
	long	end;

	end = interval + get_now();
	while (end > get_now())
		usleep(50);
	return (1);
}
