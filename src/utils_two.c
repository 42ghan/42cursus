/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:57:42 by ghan              #+#    #+#             */
/*   Updated: 2021/07/05 15:57:54 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	double_arr_len(char **ptr)
{
	int	len;

	len = 0;
	while (ptr[len])
		len++;
	return (len);
}

void	free_double_arr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

int	check_int_range(char *nbr)
{
	if (((nbr[0] >= '0' && nbr[0] <= '9') || nbr[0] == '+')
		&& ft_atoi(nbr) < 0)
		return (0);
	else if (nbr[0] == '-' && ft_atoi(nbr) >= 0)
		return (0);
	return (1);
}

void	error_exit(int code)
{
	write(2, "Error\n", 7);
	exit(code);
}

char	*hex_uitoa(unsigned int n)
{
	char	*ret;
	int		i;

	ret = (char *)ft_calloc(11, 1);
	if (!ret)
		return (NULL);
	i = 9;
	while (i >= 0)
	{
		ret[i] = "0123456789"[n % 10];
		n /= 10;
		i--;
	}
	return (ret);
}
