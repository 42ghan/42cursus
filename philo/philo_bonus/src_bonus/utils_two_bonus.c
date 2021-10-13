/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:53:06 by ghan              #+#    #+#             */
/*   Updated: 2021/10/13 22:53:15 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	free_alloc(t_philo *philo, sem_t *print_s)
{
	t_philo	*cur;

	sem_close(print_s);
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
		sem_close(philo->fork);
		free(philo);
		philo = NULL;
	}
}
