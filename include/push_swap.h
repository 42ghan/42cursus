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

typedef struct s_head
{
	struct s_stack	*start;
	int				len;
}				t_head;


size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
int				*arg_check(int argc, char *argv[]);
void    		error_exit(int  code); /* NOTE - arg error : 1; malloc error : 2 */
int				double_arr_len(char **ptr);
void    		free_double_arr(char **ptr);
int				*get_qsort_key(int *nbrs);
int				check_int_range(char *nbr);
t_stack			*stack_pop(t_head **head);
void			elem_to_top(t_head **head, t_stack *elem);
void			init_stack(t_head **head, int *nbrs);
unsigned int	*int_to_unsigned_arr(int *nbrs);
int				*unsigned_to_int_arr(int *nbrs, unsigned int *u_nbrs);

/* NOTE - stack operations */
void			swap_top_two(t_head **head);
void			push_top(t_head **from, t_head **to);
void			rot_n_rev_rot(t_head **head, int direction);

void			qsort_stack_large(t_head **a_head, t_head **b_head, int key);
void			qsort_stack_mid(t_head **a_head, t_head **b_head, int key);
void			move_small(t_head **a_head, t_head **b_head);

#endif