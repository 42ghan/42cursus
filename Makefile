# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 15:28:14 by ghan              #+#    #+#              #
#    Updated: 2021/06/30 15:28:14 by ghan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

CLIENT		=	client

SERVER		=	server

NAME		=	minitalk

ifdef WHICH_PROGRAM
	SRCS	=	src/server.c src/utils.c
else
	SRCS	=	src/client.c src/utils.c
endif

INCDIR		=	include/

OBJS	=	$(SRCS:.c=.o)


all			:	$(NAME)

$(NAME)		:	$(CLIENT) $(SERVER)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(CLIENT)	:	src/client.o src/utils.o
				$(CC) $(CFLAGS) -o $@ $^

$(SERVER)	:	src/server.o src/utils.o
				$(CC) $(CFLAGS) -o $@ $^

clean		:
				$(RM) src/client.o src/server.o src/utils.o

fclean		:	clean
				$(RM) $(CLIENT) $(SERVER)

re			:	fclean all

.PHONY		:	all clean fclean re
