/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:59:35 by ghan              #+#    #+#             */
/*   Updated: 2021/10/13 21:59:42 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_now(void)
{
	struct timeval	now;
	long			ret;

	gettimeofday(&now, NULL);
	ret = (long)now.tv_sec * 1000000 + (long)now.tv_usec;
	return (ret);
}

long	time_cal(long start_t)
{
	long	ret;

	ret = (get_now() - start_t) / 1000;
	return (ret);
}

int	ft_usleep(long interval)
{
	long	end;

	end = interval + get_now();
	while (end > get_now())
		usleep(50);
	return (1);
}
