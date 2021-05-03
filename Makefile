# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 20:01:24 by ghan              #+#    #+#              #
#    Updated: 2021/05/03 20:31:34 by ghan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCDIR	= srcs
INCDIR	= includes
SRCS	= $(wildcard $(SRCDIR)/*.c)
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
ARFLAGS	= rcs
RM		= rm -f

all		:	$(NAME)

$(OBJS)	:	$(SRCS)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME) :	$(OBJS)
			ar $(ARFLAGS) $@ $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all, clean, fclean , re
