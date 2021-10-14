/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:18:59 by ghan              #+#    #+#             */
/*   Updated: 2021/10/14 13:10:36 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	pthread_mutex_t	print_m;
	int				n_eat;
	int				vital;
	t_opt			opts;
	t_philo			*head;

	if (!check_fill_opts(argc, argv, &opts)
		|| !prepare_the_table(&head, opts, &n_eat, &print_m))
		return (EXIT_FAILURE);
	start_dinner(head->next, opts, get_now(), &vital);
	monitor_death(head->next, opts, &print_m, &vital);
	free_alloc(head);
	return (EXIT_SUCCESS);
}
