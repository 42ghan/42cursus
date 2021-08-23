<<<<<<< HEAD
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
=======
NAME	=	so_long
>>>>>>> so_long/master

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

<<<<<<< HEAD
RM		=	rm -f

SRCS		=	src/check_argv.c src/ft_split.c src/push_swap.c src/sort_modules.c\
			src/sort_stacks.c src/sort_three_five.c src/sorted_ints.c src/stack_ops.c\
			src/utils_radix.c src/utils_gen_one.c src/utils_sort.c src/utils_stack.c\
			src/utils_gen_two.c src/write_ops.c


INCDIR	=	include/

OBJS	=	$(SRCS:.c=.o)
=======
FRWRK	=	-framework OpenGL -framework AppKit

RM		=	rm -f

MLX_DIR =	minilibx/

SRCS	=	src/main.c\
			src/get_next_line.c\
			src/map_parse.c\
			src/display.c\
			src/key_events.c\
			src/utils_lists.c\
			src/utils_one.c\
			src/utils_two.c

SRCS_B	=	bonus/main_bonus.c\
			bonus/get_next_line_bonus.c\
			bonus/map_parse_bonus.c\
			bonus/display_bonus.c\
			bonus/image_bonus.c\
			bonus/key_events_bonus.c\
			bonus/utils_lists_bonus.c\
			bonus/utils_one_bonus.c\
			bonus/utils_two_bonus.c			

O_MAN	=	$(SRCS:.c=.o)

O_BON	=	$(SRCS_B:.c=.o)

ifdef WITH_BONUS
	OBJS	=	$(O_BON)
	INCDIR	=	bonus/
else
	OBJS	=	$(O_MAN)
	INCDIR	=	include/
endif
>>>>>>> so_long/master

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

<<<<<<< HEAD
$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

clean	:
			$(RM) $(OBJS)
=======
bonus	:
			make WITH_BONUS=1 all

$(NAME)	:	$(OBJS)
			make -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(FRWRK) -o $@ $^ -L $(MLX_DIR) -l mlx

clean	:
			make clean -C $(MLX_DIR)
			$(RM) $(O_MAN) $(O_BON)
>>>>>>> so_long/master

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
