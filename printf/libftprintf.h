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
	size_t			start;
	size_t			end;
	int				align;
	int				zero;
	int				width;
	int				prec;
	int				isprec;
	int				len;
	char			form;
	char			*flag;
	char			*prnt;
}				t_flist;

void			prcss_addr(t_flist *spec, va_list *ap);
void			prcss_c_or_str(t_flist *spec, va_list *ap, char f);
void			prcss_hex(t_flist *spec, va_list *ap, char f);
void			flags_to_ints_hex(t_flist *spec, char *tmp, int len);
void			prcss_ints(t_flist *spec, va_list *ap, char f);
void			check_flags(t_flist *spec, va_list *ap);
int				digit_cnt(int n);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
void			prcss_perc(t_flist *cur);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
char			*strncpy_no_null(char *dst, const char *src, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			spec_initialize(t_flist *spec);
void			clear_spec(t_flist *spec);
size_t			print_and_count(t_flist *spec);
int				ft_printf(const char *format, ...);

#endif
