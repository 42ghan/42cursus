/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:54:37 by ghan              #+#    #+#             */
/*   Updated: 2021/06/27 22:54:37 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t count, size_t size);
char		*ft_uitoa(unsigned int n);
int			ft_atoi(const char *str);

#endif
