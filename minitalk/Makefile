# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD
#    Created: 2021/06/04 22:07:11 by ghan              #+#    #+#              #
#    Updated: 2021/06/04 22:07:12 by ghan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

SRCS	= 	ft_printf.c\
			utils.c\
			utils_two.c\
			utils_three.c\
			print_clear.c\
			flags.c\
			address.c\
			char_or_str.c\
			hex.c\
			ints.c\

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

ARFLAGS	=	rcs

RM		=	rm -f

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I .

$(NAME)	:	$(OBJS)
			ar $(ARFLAGS) $@ $^

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re all
=======
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

SRCS		=	src/server.c src/client.c src/utils.c

SRCS_B		=	bonus/server_bonus.c bonus/client_bonus.c bonus/utils_bonus.c

O_MAN		=	$(SRCS:.c=.o)

O_BON		=	$(SRCS_B:.c=.o)

ifdef WITH_BONUS
	INCDIR	=	bonus/
else
	INCDIR	=	include/
endif

all			:	$(NAME)

$(NAME)		:	$(CLIENT) $(SERVER)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

ifdef WITH_BONUS
$(CLIENT)	:	bonus/client_bonus.o bonus/utils_bonus.o
				$(CC) $(CFLAGS) -o $@ $^

$(SERVER)	:	bonus/server_bonus.o bonus/utils_bonus.o
				$(CC) $(CFLAGS) -o $@ $^
else
$(CLIENT)	:	src/client.o src/utils.o
				$(CC) $(CFLAGS) -o $@ $^

$(SERVER)	:	src/server.o src/utils.o
				$(CC) $(CFLAGS) -o $@ $^
endif

bonus		:
				make WITH_BONUS=1 all

clean		:
				$(RM) $(O_MAN) $(O_BON)

fclean		:	clean
				$(RM) $(CLIENT) $(SERVER)

re			:	fclean all

.PHONY		:	all clean fclean re bonus
>>>>>>> minitalk/master
