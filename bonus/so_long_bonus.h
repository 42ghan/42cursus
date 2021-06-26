/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:17:24 by ghan              #+#    #+#             */
/*   Updated: 2021/06/24 19:02:58 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../minilibx/mlx.h"

typedef struct	s_ln_lst
{
	char			*line;
	int				line_num;
	int				len;
	struct s_ln_lst	*next;
}				t_ln_lst;

typedef struct	s_mlx_bag
{
	t_ln_lst	**map;
	void		*mlx;
	void		*win;
	void		*wall;
	void		*empty;
	void		*col;
	void		*col_two;
	void		*patrol;
	void		*pat_two;
	void		*cnt_collect;
	void		*start;
	void		*exit;
	void		*p_img;
	int			p_x;
	int			p_y;
	int			col_num;
	int			first;
	int			time;
	int			moves;
	int			result;
	char		*moves_str;
}				t_mlx_bag;

size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_calloc(size_t count, size_t size);
char			*ft_uitoa(unsigned int n);

int				get_next_line(int fd, char **line);
void			fill_ln_lst(t_ln_lst **head, int fd);
int				check_map_validity(t_ln_lst **head);
t_ln_lst		*ft_ln_lstnew(void *content, int num);
void			ft_ln_lstadd_back(t_ln_lst **lst, t_ln_lst *new);
t_ln_lst		*ft_ln_lstlast(t_ln_lst *lst);
void			clear_ln_lst(t_ln_lst **head);
t_ln_lst		*find_cur_line(t_mlx_bag *bag, int line_num);

int				close_window(t_mlx_bag *bag);
int				key_press(int keycode, t_mlx_bag *bag);
void			str_malloc_error(t_mlx_bag *bag);
int				put_tiles(t_mlx_bag *bag);
void			free_images(t_mlx_bag *bag);
int				mlx_bag_init(void *mlx, void *win, t_ln_lst **line,
t_mlx_bag *bag);
void			image_to_window(t_mlx_bag *b, char c, int x, int y);
void			patrol_positions(t_ln_lst *cur);
int				collect_count(t_ln_lst *cur);

#endif
