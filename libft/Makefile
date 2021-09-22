# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 20:01:24 by ghan              #+#    #+#              #
#    Updated: 2021/09/22 22:50:13 by ghan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS_MAN	= ft_memset.c\
			  ft_bzero.c\
			  ft_memcpy.c\
			  ft_memccpy.c\
			  ft_memmove.c\
			  ft_memchr.c\
			  ft_memcmp.c\
			  ft_strlen.c\
			  ft_strlcpy.c\
			  ft_strlcat.c\
			  ft_strchr.c\
			  ft_strrchr.c\
			  ft_strnstr.c\
			  ft_strncmp.c\
			  ft_atoi.c\
			  ft_isalpha.c\
			  ft_isdigit.c\
			  ft_isalnum.c\
			  ft_isascii.c\
			  ft_isprint.c\
			  ft_toupper.c\
			  ft_tolower.c\
			  ft_calloc.c\
			  ft_strdup.c\
			  ft_substr.c\
			  ft_strjoin.c\
			  ft_strtrim.c\
			  ft_split.c\
			  ft_itoa.c\
			  ft_strmapi.c\
			  ft_putchar_fd.c\
			  ft_putstr_fd.c\
			  ft_putendl_fd.c\
			  ft_putnbr_fd.c\

SRCS_BON	= ft_lstnew.c\
			  ft_lstadd_front.c\
			  ft_lstsize.c\
			  ft_lstlast.c\
			  ft_lstadd_back.c\
			  ft_lstdelone.c\
			  ft_lstclear.c\
			  ft_lstiter.c\
			  ft_lstmap.c\

OBJS_MAN	= $(SRCS_MAN:.c=.o)

OBJS_BON	= $(SRCS_BON:.c=.o)

ifdef WITH_BONUS
	OBJS	= $(OBJS_MAN) $(OBJS_BON)
else
	OBJS	= $(OBJS_MAN)
endif

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

ARFLAGS		= rcs

RM			= rm -f

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@ -I .

$(NAME)		:	$(OBJS)
				ar $(ARFLAGS) $@ $^

bonus		:
				make WITH_BONUS=1 all
clean		:
				$(RM) $(OBJS_MAN) $(OBJS_BON)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all bonus clean fclean re