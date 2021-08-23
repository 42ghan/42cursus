/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:54:37 by ghan              #+#    #+#             */
/*   Updated: 2021/06/27 22:54:37 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t count, size_t size);
char		*ft_uitoa(unsigned int n);
int			only_pos_atoi(const char *str);
void		sa_init(struct sigaction *sa,
void (*f)(int, struct __siginfo *, void *));

#endif
