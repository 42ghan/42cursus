/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:46:25 by ghan              #+#    #+#             */
/*   Updated: 2021/11/21 00:58:49 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define HEAD_ELEM -2

typedef struct	s_lst
{
	int				fd;
	char			*backup;
	struct s_lst	*next;
}				t_lst;

size_t			ft_strlen(const char *s);
void			ft_lstadd_back(t_lst **lst, t_lst *new);
t_lst			*ft_lstnew(void *content, int fd);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
int				get_next_line(int fd, char **line);

#endif
