/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:59:47 by ghan              #+#    #+#             */
/*   Updated: 2021/08/23 14:59:47 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

int	ft_atoi(const char *str)
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

void	free_alloc(t_philo *philo)
{
	t_philo	*cur;

	while (philo)
	{
		cur = philo->next;
		free(philo);
		philo = cur->next;
	}
}
