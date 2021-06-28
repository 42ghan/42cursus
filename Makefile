NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

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

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

bonus	:
			make WITH_BONUS=1 all

$(NAME)	:	$(OBJS)
			make -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(FRWRK) -o $@ $^ -L $(MLX_DIR) -l mlx

clean	:
			make clean -C $(MLX_DIR)
			$(RM) $(O_MAN) $(O_BON)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
