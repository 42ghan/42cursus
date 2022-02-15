/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:59:47 by ghan              #+#    #+#             */
/*   Updated: 2021/11/22 11:32:04 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
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
	int		ret;
	size_t	i;

	ret = 0;
	i = 0;
	if (ft_strlen(str) > 10
		|| (ft_strlen(str) == 10 && str[0] > '2'))
		return (-1);
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		ret = ret * 10 + str[i++] - '0';
	if (i != ft_strlen(str))
		return (-1);
	return (ret);
}

void	free_alloc(t_philo *philo)
{
	t_philo	*cur;

	if (!philo)
		return ;
	cur = philo->next;
	free(philo);
	philo = cur;
	while (philo->next != cur)
		philo = philo->next;
	philo->next = NULL;
	philo = cur;
	while (cur)
	{
		philo = cur;
		cur = philo->next;
		pthread_mutex_destroy(&(philo->fork));
		free(philo);
		philo = NULL;
	}
}
