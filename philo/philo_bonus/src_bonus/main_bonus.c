/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:11:47 by ghan              #+#    #+#             */
/*   Updated: 2021/10/13 22:50:22 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_opt		opts;
	t_philo		*head;
	sem_t		*print_s;

	print_s = NULL;
	if (!check_fill_opts(argc, argv, &opts)
		|| !prepare_the_table(&head, opts, print_s))
		return (EXIT_FAILURE);
	dine_with_fork(head->next, opts);
	free_alloc(head, print_s);
	return (EXIT_SUCCESS);
}
