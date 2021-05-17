/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:33:33 by ghan              #+#    #+#             */
/*   Updated: 2021/05/14 15:16:26 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int				fd;
	char			*backup;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *s);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_lstdelone(t_list *lst, t_list **prev, void (*del)(void*));
t_list			*ft_lstnew(void *content, int fd);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				get_next_line(int fd, char **line);

#endif
