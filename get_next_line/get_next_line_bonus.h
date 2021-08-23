/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:46:25 by ghan              #+#    #+#             */
/*   Updated: 2021/05/17 16:29:58 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

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
