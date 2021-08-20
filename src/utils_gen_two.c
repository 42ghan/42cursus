/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gen_two.c                                    :+:      :+:    :+:   */
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
	int	skip_len;

	skip_len = 0;
	if (nbr[0] == '-' || nbr[0] == '+')
		skip_len++;
	while (nbr[skip_len] == '0')
		skip_len++;
	if (ft_strlen(nbr) - skip_len > 11)
		return (0);
	if (((nbr[0] >= '0' && nbr[0] <= '9') || nbr[0] == '+')
		&& ft_atoi(nbr) < 0)
		return (0);
	else if (nbr[0] == '-' && ft_atoi(nbr) >= 0)
		return (0);
	return (1);
}

void	error_exit(int code)
{
	write(2, "Error\n", 6);
	exit(code);
}
