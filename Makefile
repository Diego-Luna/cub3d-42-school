# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 08:29:42 by atopalli          #+#    #+#              #
#    Updated: 2023/02/25 01:17:51 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS
NAME	=	cub3D
FLAGS	=	-Wall -Wextra -Werror -framework Cocoa -framework OpenGL -framework IOKit
CC		=	gcc $(FLAGS)

# FILES
SRCSDIR	=	srcs/
SRCS	=	$(SRCSDIR)main.c		\

UTLSDIR	=	utils/
UTILS	=	$(UTLSDIR)parsing.c		\
			$(UTLSDIR)gnl/gnl.c		\
			$(UTLSDIR)start_state.c	\
			$(UTLSDIR)save_map.c	\

# MLX
USER	=	$(shell whoami)
MLXLIB	=	includes/mlx/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

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
		sleep 0.233; \
		echo "$(YELLOW)Compiling: $(RESET)$$i"; \
	done
	@$(CC)	$(SRCS) $(UTILS) $(MLXLIB) -o $(NAME)
	@sleep 	0.333
	@echo	"$(GREEN)$(NAME) created$(RESET)"

clean:
	@for i in $(SRCS) $(UTILS); do \
		sleep 0.333; \
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
