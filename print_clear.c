/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:25:41 by ghan              #+#    #+#             */
/*   Updated: 2021/06/04 20:25:42 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	clear_spec(t_flist *spec)
{
	free(spec->flag);
	spec->flag = NULL;
	free(spec->prnt);
	spec->prnt = NULL;
}

size_t	print_and_count(t_flist *spec)
{
	size_t	ret_cnt;
	int		i;

	ret_cnt = 0;
	if (spec->form == 'c')
	{
		i = 0;
		while (i < spec->len)
		{
			write(1, &(spec->prnt[i]), 1);
			ret_cnt++;
			i++;
		}
	}
	else
	{
		write(1, spec->prnt, ft_strlen(spec->prnt));
		ret_cnt += ft_strlen(spec->prnt);
	}
	clear_spec(spec);
	return (ret_cnt);
}
