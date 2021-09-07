# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 12:10:40 by ghan              #+#    #+#              #
#    Updated: 2021/09/03 12:10:41 by ghan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

SRCS	=	src_bonus/philo_bonus.c src_bonus/utils_bonus.c\
			src_bonus/routine_bonus.c src_bonus/init_lst_bonus.c

INCDIR	=	incl_bonus/

OBJS	=	$(SRCS:.c=.o)


all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all fclean clean re bonus

