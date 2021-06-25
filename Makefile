NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

FRWRK	=	-framework OpenGL -framework AppKit

RM		=	rm -f

INC_DIR	=	include/

MLX_DIR =	minilibx/

SRCS	=	src/main.c\
			src/get_next_line.c\
			src/map_parse.c\
			src/display.c\
			src/key_events.c\
			src/utils_lists.c\
			src/utils_one.c\
			src/utils_two.c

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME)	:	$(OBJS)
			make -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(FRWRK) -o $@ $^ -L $(MLX_DIR) -l mlx

clean	:
			make clean -C $(MLX_DIR)
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
