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
# include <signal.h>

typedef struct s_opt
{
	int	n_philo;
	int	time_die;
	int	time_eat;
	int	time_slp;
	int	n_must_eat;
}				t_opt;

typedef struct s_philo
{
	pid_t			pid;
	int				idx;
	int				*n_eat;
	long			start_t;
	long			last_eat_t;
	t_opt			opts;
	sem_t			*print_s;
	sem_t			*fork;
	struct s_philo	*next;
}				t_philo;

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_pos_atoi(const char *str);
char	*ft_pos_itoa(int n);
void	free_alloc(t_philo *philo);
long	get_now(void);
t_philo	*philo_new(t_opt opts, int *n_eat, sem_t *print_s, int idx);
int		init_philo_profile(t_philo **head, t_opt opts, int *n_eat,
			sem_t *print_s);
void	start_dinner(t_philo *philo);

#endif
