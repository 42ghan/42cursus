/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:14:17 by ghan              #+#    #+#             */
/*   Updated: 2021/10/14 12:44:04 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

/* USER DEFININTION */

# define ENJOY_WHILE_ALIVE 0
# define ADIOS_PHILO 1
# define FULL_STOMACH 2
# define NO_SHOW 3

typedef struct s_opt
{
	int		n_philo;
	long	time_die;
	long	time_eat;
	long	time_slp;
	int		n_must_eat;
}				t_opt;

typedef struct s_philo
{
	pthread_t		tid;
	int				idx;
	int				*n_eat;
	int				*vital;
	long			last_eat_t;
	long			start_t;
	t_opt			opts;
	pthread_mutex_t	fork;
	pthread_mutex_t	*print_m;
	struct s_philo	*next;
}				t_philo;

/* FUNCITONS */

/* Utils */

size_t		ft_strlen(const char *s);
void		ft_putendl_fd(char *s, int fd);
void		*ft_calloc(size_t count, size_t size);
int			ft_pos_atoi(const char *str);
void		free_alloc(t_philo *philo);

/* Preparation */

int			check_fill_opts(int ac, char **av, t_opt *opts);
int			prepare_the_table(t_philo **head, t_opt opts, int *n_eat,
				pthread_mutex_t *print_m);
int			init_philo_profile(t_philo *head, t_opt opts, int *n_eat,
				pthread_mutex_t *print_m);
t_philo		*philo_new(t_opt opts, int *n_eat, pthread_mutex_t *print_m);

/* Dinner Time */

void		*philo_action(void *arg);
void		start_dinner(t_philo *cur, t_opt opts, long start_t, int *vital);
void		monitor_death(t_philo *cur, t_opt opts,
				pthread_mutex_t *print_m, int *vital);

/* Time is Gold */

long		get_now(void);
long		time_cal(long start_t);
int			ft_usleep(long interval);

#endif
