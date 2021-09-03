# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 11:22:46 by ghan              #+#    #+#              #
#    Updated: 2021/08/23 11:22:47 by ghan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

SRCS	=	src/philo.c src/utils.c src/philo_routine.c src/init_lst.c

INCDIR	=	include/

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
