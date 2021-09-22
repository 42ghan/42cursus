/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:33:29 by ghan              #+#    #+#             */
/*   Updated: 2021/09/22 21:45:41 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	check_extremes(unsigned long long ret, int sign)
{
	if (sign == 1 && ret > LLONG_MAX - 1)
		ret = -1;
	else if (sign == -1 && ret > LLONG_MAX)
		ret = 0;
	return (ret);
}

int	ft_atoi(const char *str)
{
	unsigned long long	ret;
	int					i;
	int					sign;

	sign = 1;
	ret = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	return (check_extremes(ret, sign) * sign);
}
