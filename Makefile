NAME	= so_long

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

INC_DIR	= include/

MLX_DIR = minilibx/

SRCS	= src/main.c

OBJS	= $(SRCS:.c=.o)

all		:	$(NAME)

%.c		:	%.o
			make -C $(MLX_DIR)
 			$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^ -L $(MLX_DIR)

clean	:
			make clean -C $(MLX_DIR)
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re


