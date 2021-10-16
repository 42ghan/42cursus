/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:11:47 by ghan              #+#    #+#             */
/*   Updated: 2021/10/16 15:59:02 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_opt		opts;
	t_philo		*head;
	sem_t		*print_s;
	sem_t		*forks_s;
	sem_t		*full_s;

	print_s = NULL;
	forks_s = NULL;
	full_s = NULL;
	if (!check_fill_opts(argc, argv, &opts)
		|| !prep_the_table(&head, opts, print_s, forks_s))
		return (EXIT_FAILURE);
	if (opts.n_must_eat > 0)
		if (!exercise_self_control(head->next, full_s, print_s, forks_s))
			return (EXIT_FAILURE);
	dine_with_fork(head->next, opts);
	free_alloc(head, print_s, forks_s, full_s);
	return (EXIT_SUCCESS);
}
