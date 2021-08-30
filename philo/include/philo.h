/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:14:17 by ghan              #+#    #+#             */
/*   Updated: 2021/08/23 12:14:18 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* TODO - remove stdio.h */
#include <stdio.h>

typedef	struct	s_opt
{
	int		n_philo;
	int		time_die;
	int		time_eat;
	int		time_slp;
	int		n_must_eat;
}				t_opt;


typedef struct	s_philo
{
	pthread_t		tid;
	int				*vital;
	int				nth;
	int				n_eat;
	long			prev_t;
	char			cur_act;
	t_opt			opts;
	pthread_mutex_t	fork;
	struct s_philo	*next;
}				t_philo;



size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *str);
void			free_alloc(t_philo *philo, int n);

#endif

