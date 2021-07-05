# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 12:02:01 by ghan              #+#    #+#              #
#    Updated: 2021/07/05 12:02:03 by ghan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

SRC		=	src/

INCDIR	=	include/

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I .

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
