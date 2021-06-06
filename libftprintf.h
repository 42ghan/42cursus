/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:10:10 by ghan              #+#    #+#             */
/*   Updated: 2021/06/04 17:10:12 by ghan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flist
{
	unsigned int	start;
	unsigned int	end;
	int				ast_cnt;
	int				align;
	int				zero;
	int				width;
	int				prec;
	char			form;
	char			*flag;
	char			*prnt;
	struct s_flist *next;
}				t_flist;

void		prcss_addr(t_flist *cur, va_list *ap);
void		prcss_c_or_str(t_flist *cur, va_list *ap, char f);
void		flags_to_ints_hex(t_flist *cur, char *tmp, int len);
void		prcss_ints(t_flist *cur, va_list *ap, char f);
void		prcss_hex(t_flist *cur, va_list *ap, char f);
void		check_flags(t_flist *cur, va_list *ap);
void		clear_list(t_flist **forms);
size_t		print_str(char *str, t_flist *forms);
int			ft_isdigit(int c);
char		*strncpy_no_null(char *dst, const char *src, size_t size);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		flist_add_back(t_flist **lst, t_flist *new);
t_flist		*flist_init(void);
int			ft_printf(const char *format, ...);

#endif
