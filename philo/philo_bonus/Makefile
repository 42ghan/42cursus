# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghan <ghan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 11:22:46 by ghan              #+#    #+#              #
#    Updated: 2021/10/13 22:54:57 by ghan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo_bonus

CC				=	gcc

ifdef DEBUG
	CFLAGS		=	-g3 -fsanitize=address
else ifdef LEAKS
	CFLAGS		=	-g
else
	CFLAGS		=	-Wall -Werror -Wextra
endif

RM				=	rm -f

SRCS_BONUS_DIR	=	./src_bonus/

SRCS_BONUS		=	$(addprefix $(SRCS_BONUS_DIR), \
						main_bonus.c\
						utils_bonus.c\
						utils_two_bonus.c\
						routine_bonus.c\
						philo_lst_bonus.c\
						dinner_time_bonus.c\
						prep_bonus.c\
						time_bonus.c\
						)

INC_DIR_BONUS	=	./incl_bonus/

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)


############################# Color #############################

GREEN="\033[32m"
L_GREEN="\033[1;32m"
YELLOW="\033[33m"
RED="\033[31m"
L_RED="\033[1;31m"
BLUE="\033[34m"
L_BLUE="\033[1;34m"
MUTED="\033[130m"
RESET="\033[0m"
BOLD="\033[1m"
L_PUPLE="\033[1;35m"
UP = "\033[A"
DOWN = "\033[B"
RIGHT = "\033[C"
LEFT = "\033[D"
CUT = "\033[K"
SAVE = "\033[s"
RESTORE = "\033[u"


############################# RULE #############################

.PHONY			:	all
all				:	$(NAME)

%.o				:	%.c
					@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR_BONUS)
					@echo $(SAVE)$(CUT)$(BOLD)$(L_GREEN) Compiling with $(CFLAGS)...$(RESET)
					@echo $(CUT)$(GREEN) [$(notdir $^)] to [$(notdir $@)] $(RESET)

$(NAME)			:	$(OBJS_BONUS)
					@$(CC) $(CFLAGS) -o $@ $^
					@echo $(BOLD)$(L_RED) 💀 🍝  DEADLY DINNER TIME! 🤔 💀 $(RESET)

.PHONY			:	clean
clean			:
					@$(RM) $(OBJS_BONUS)
					@echo $(BOLD)$(L_RED) 🧹 remove object files ✨ $(RESET)

.PHONY			:	fclean
fclean			:	clean
					@$(RM) $(NAME)
					@echo $(BOLD)$(L_RED) 🧹 remove executable file ✨ $(RESET)

.PHONY			:	re
re				:	fclean all

.PHONY			:	debug
debug			:
					@make DEBUG=1
					@echo $(BOLD)$(L_BLUE) 🔎 🔦 catch the BUG! 🐞 $(RESET)

.PHONY			:	leaks
leaks			:
					@make LEAKS=1
					@echo $(BOLD)$(L_BLUE) 🔎 🔦 where\'s memory leaking? 💦 $(RESET)

