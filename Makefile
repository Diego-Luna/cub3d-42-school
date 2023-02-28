# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 08:29:42 by atopalli          #+#    #+#              #
#    Updated: 2023/02/28 11:52:01 by dluna-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS
NAME	=	cub3D
FLAGS	=	-g -Wall -Wextra -Werror -framework Cocoa -framework OpenGL -framework IOKit
# FLAGS	=	-g -Wall -Wextra -Werror
CC		=	gcc $(FLAGS)

# FILES
SRCSDIR	=	srcs/
SRCS	=	$(SRCSDIR)main.c		\
			$(SRCSDIR)validate.c	\

UTLSDIR	=	utils/
UTILS	=	$(UTLSDIR)parsing.c		\
			$(UTLSDIR)gnl/gnl.c		\
			$(UTLSDIR)start_state.c	\
			$(UTLSDIR)save_map.c	\
			$(UTLSDIR)allocation.c		\
			$(UTLSDIR)valid_map.c		\
			$(UTLSDIR)error_and_free.c		\
			$(UTLSDIR)save_player.c		\

# MLX
USER	=	$(shell whoami)
MLXLIB	=	includes/mlx/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
# MLXLIB	=	includes/mlx/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"

# HEADERS
HEADERS	=	includes/cub3d.h

# Colors
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m
RESET	=	\033[0m

# RULES
all:		$(NAME)

$(NAME):	$(SRCS) $(UTILS)
	@for i in $(SRCS) $(UTILS); do \
		sleep 0.123; \
		echo "$(YELLOW)Compiling: $(RESET)$$i"; \
	done
	@$(CC)	$(SRCS) $(UTILS) $(MLXLIB) -o $(NAME)
	@sleep 	0.321
	@echo	"$(GREEN)$(NAME) created$(RESET)"

clean:
	@for i in $(SRCS) $(UTILS); do \
		sleep 0.213; \
		echo "$(RED)Deleting: $(RESET)$$i.o"; \
		rm -f $$i.o; \
	done

fclean:		clean
			@rm -f $(NAME)
			@echo	"$(PURPLE)$(NAME) deleted$(RESET)"

norm:
	@norminette $(SRCS) $(UTILS) $(HEADERS)

re:			fclean all

.PHONY: all clean fclean re norm
