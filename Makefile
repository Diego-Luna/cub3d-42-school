# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 08:29:42 by atopalli          #+#    #+#              #
#    Updated: 2023/02/23 09:57:37 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARS
NAME	=	cub3D
FLAGS	=	-Wall -Wextra -Werror
CC		=	gcc $(FLAGS)

# FILES
SRCSDIR	=	srcs/
SRCS	=	$(SRCSDIR)main.c		\

UTLSDIR	=	utils/
UTILS	=	$(UTLSDIR)parsing.c		\
			$(UTLSDIR)gnl/gnl.c		\


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
	@$(CC)	$(SRCS) $(UTILS) -o $(NAME)
	@echo	"$(GREEN)$(NAME) created$(RESET)"

clean:
	@rm -f	$(NAME)
	@echo	"$(PURPLE)$(NAME) deleted$(RESET)"

fclean:		clean

re:			fclean all

.PHONY: all clean fclean re
