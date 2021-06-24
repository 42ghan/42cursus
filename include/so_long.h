/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:17:24 by ghan              #+#    #+#             */
/*   Updated: 2021/06/21 21:17:25 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* NOTE - including headers for alowed funcitons */
# include <stdlib.h> 
# include <fcntl.h> /* for open */
# include <unistd.h> /* for close, read, write */
# include <stdio.h> /* for perror */
# include <mlx.h> /* for miniLibX functions */

/* NOTE - map lines list */
typedef struct	s_ln_lst
{
	char			*line;
	int				line_num;
	int				len;
	struct s_ln_lst	*next;
}				t_ln_lst;

/* NOTE - img bag structure */
typedef struct	s_img_bag
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*empty;
	void	*collect;
	void	*player;
	void	*start;
	void	*exit;
}				t_img_bag;

/* NOTE - utils_one funcitons */
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);

/* NOTE - utils_lists functions */
t_ln_lst	*ft_ln_lstnew(void *content, int num);
void		ft_ln_lstadd_back(t_ln_lst **lst, t_ln_lst *new);
t_ln_lst	*ft_ln_lstlast(t_ln_lst *lst);
void		clear_ln_lst(t_ln_lst **head);

/* NOTE - gnl */
int			get_next_line(int fd, char **line);

/* NOTE - map parse */
void		fill_ln_lst(t_ln_lst **head, int fd);
int			check_map_validity(t_ln_lst **head);

#endif
