/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:53:06 by ghan              #+#    #+#             */
/*   Updated: 2021/10/18 00:10:58 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	free_alloc(t_philo *ph, sem_t *print_s, sem_t *forks_s, sem_t *full_s)
{
	t_philo	*cur;

	sem_close(print_s);
	sem_unlink("print");
	sem_close(forks_s);
	sem_unlink("forks");
	sem_close(full_s);
	sem_unlink("full");
	cur = ph->next;
	free(ph);
	ph = cur;
	while (ph->next != cur)
		ph = ph->next;
	ph->next = NULL;
	ph = cur;
	while (cur)
	{
		ph = cur;
		cur = ph->next;
		free(ph);
		ph = NULL;
	}
}

void	kill_philos(t_philo *philo, int n)
{
	while (--n >= 0)
	{
		kill(philo->pid, SIGINT);
		philo = philo->next;
	}
}
