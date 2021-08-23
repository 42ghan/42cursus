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

SRCS		=	src/check_argv.c src/ft_split.c src/push_swap.c src/sort_modules.c\
			src/sort_stacks.c src/sort_three_five.c src/sorted_ints.c src/stack_ops.c\
			src/utils_radix.c src/utils_gen_one.c src/utils_sort.c src/utils_stack.c\
			src/utils_gen_two.c src/write_ops.c


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

.PHONY	:	all clean fclean re bonus
