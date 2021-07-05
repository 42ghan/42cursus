/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:09:37 by ghan              #+#    #+#             */
/*   Updated: 2021/07/05 12:09:38 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

/* NOTE - stack element structure definition */
typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		*arg_check(int argc, char *argv[]);
void    error_exit(int  code); /* NOTE - arg error : 1; malloc error : 2 */
int		double_arr_len(char **ptr);
void    free_double_arr(char **ptr);

#endif