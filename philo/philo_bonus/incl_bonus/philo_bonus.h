/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:11:39 by ghan              #+#    #+#             */
/*   Updated: 2021/09/03 11:11:39 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
/* NOTE - why phtread.h? */
# include <pthread.h>

typedef struct s_opt
{
	int		n_philo;
	int		time_die;
	int		time_eat;
	int		time_slp;
	int		n_must_eat;
}				t_opt;

typedef struct s_philo
{
	pid_t			pid;
	pthread_t		tid;
	int				idx;
	int				n_eat;
	long			start_t;
	long			last_eat_t;
	t_opt			opts;
	struct s_philo	*next;
}				t_philo;

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
long	get_now(void);

#endif
