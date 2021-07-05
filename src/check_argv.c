/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:24:59 by ghan              #+#    #+#             */
/*   Updated: 2021/07/05 15:25:01 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_duplicates(int *nbrs, int len)
{
	int	i;
	int	k;

	i = 1;
	while (i < len - 1)
	{
		k = i + 1;
		while (k < len)
		{
			if (nbrs[i] == nbrs[k])
				error_exit(1);
			k++;
		}
		i++;
	}
}

static int	check_int_range(char *nbr)
{
	if (((nbr[0] >= '0' && nbr[0] <= '9') || nbr[0] == '+')
		&& ft_atoi(nbr) < 0)
		return (0);
	else if (nbr[0] == '-' && ft_atoi(nbr) >= 0)
		return (0);
	return (1);
}

static int	*nbr_strs_map(char **nbr_strs, int len)
{
	int	*ret;
	int	i;
	int	k;

	ret = (int *)ft_calloc(len + 1, sizeof(int));
	if (!ret)
		error_exit(2);
	nbrs[0] = len;
	i = 0;
	while (nbr_strs[++i])
	{
		if (ft_strlen(nbr_strs[i]) > 11 || !check_int_range(nbr_strs[i]))
			error_exit(1);
		k = 0;
		if (nbr_strs[i][k] == '-' || nbr_strs[i][k] == '+')
			k++;
		while (nbr_strs[i][k])
		{
			if (nbr_strs[i][k] < '0' || nbr_strs[i][k] > '9')
				error_exit(1);
			k++;
		}
		ret[i] = ft_atoi(nbr_strs[i]);
	}
	return (ret);
}

static char	**join_n_split(int ac, char *av[])
{
	char	**ret;
	char	*one_ln;
	char	*tmp;
	int		i;

	one_ln = ft_strndup("", 1);
	if (!one_ln)
		error_exit(2);
	i = 1;
	while (i < ac)
	{
		tmp = one_ln;
		one_ln = ft_strjoin(one_ln, av[i++]);
		free(tmp);
		if (!one_ln)
			error_exit(2);
		one_ln = ft_strjoin(one_ln, " ");
		if (!one_ln)
			error_exit(2);
	}
	tmp = NULL;
	ret = ft_split(one_ln, ' ');
	if (!ret)
		error_exit(2);
	return (ret);
}

int	*arg_check(int ac, char *av[])
{
	char	**nbr_strs;
	int		*nbrs;
	int		len;

	if (ac < 2)
		error_exit(1);
	nbr_strs = join_n_split(ac, av);
	len = double_arr_len(nbr_strs);
	nbrs = nbr_strs_map(nbr_strs, len);
	free_double_arr(nbr_strs);
	check_duplicates(nbrs, len);
	return (nbrs);
}
