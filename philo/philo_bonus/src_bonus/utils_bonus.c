/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:27:21 by ghan              #+#    #+#             */
/*   Updated: 2021/09/03 12:27:22 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl_bonus/philo_bonus.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	unsigned int	i;

	ret = (unsigned char *)malloc(count * size);
	if (!ret)
		return (0);
	i = 0;
	while (i < count * size)
		*(unsigned char *)(ret + i++) = 0;
	return (ret);
}

int	ft_pos_atoi(const char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (ft_strlen(str) > 10
		|| (ft_strlen(str) == 10 && str[0] != 2))
		return (-1);
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	return (ret);
}

char	*ft_pos_itoa(int n)
{
	char	*ret;
	int		cnt;
	int		n_cpy;

	n_cpy = n;
	cnt = 1;
	while (n_cpy / 10)
	{
		n_cpy /= 10;
		cnt++;
	}
	ret = ft_calloc((cnt + 1), 1);
	if (!ret)
		return (NULL);
	while (cnt)
	{
		ret[cnt - 1] = "0123456789"[n % 10];
		n /= 10;
		cnt--;
	}
	return (ret);
}

long	get_now(void)
{
	struct timeval	now;
	long			ret;

	gettimeofday(&now, NULL);
	ret = (long)now.tv_sec * 1000000 + (long)now.tv_usec;
	return (ret);
}
