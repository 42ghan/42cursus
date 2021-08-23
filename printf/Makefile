# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
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