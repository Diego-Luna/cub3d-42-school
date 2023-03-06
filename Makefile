# **************************************************************************** #
#                                                                              #
#                                                   if(success){};             #
#    Makefile                                       ██╗  ██╗██████╗            #
#                                                   ██║  ██║╚════██╗           #
#    By: atopalli | github/atrobp                   ███████║ █████╔╝           #
#                                                   ╚════██║██╔═══╝            #
#    Created: 2023/02/23 08:29:42 by atopalli            ██║███████╗           #
#    Updated: 2023/03/06 15:07:13 by atopalli            ╚═╝╚══════╝.qc        #
#                                                                              #
# **************************************************************************** #

# VARS
PROJECT	=	cub3D
FLAGS	=	-g -Wall -Wextra -Werror -framework Cocoa -framework OpenGL -framework IOKit
# FLAGS	=	-g -Wall -Wextra -Werror
CC		=	gcc $(FLAGS)

# FILES
SRCSDIR	=	srcs/
SRCS	=	$(SRCSDIR)main.c			\
			$(SRCSDIR)validate.c		\

UTLSDIR	=	utils/
UTILS	=	$(UTLSDIR)parsing.c			\
			$(UTLSDIR)gnl/gnl.c			\
			$(UTLSDIR)start_state.c		\
			$(UTLSDIR)save_map.c		\
			$(UTLSDIR)allocation.c		\
			$(UTLSDIR)valid_map.c		\
			$(UTLSDIR)error_and_free.c	\
			$(UTLSDIR)save_player.c		\
			$(UTLSDIR)routine.c			\

# MLX
USER	=	$(shell whoami)
MLXLIB	=	includes/mlx/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
# MLXLIB	=	includes/mlx/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"

# HEADERS
HEADERS	=	includes/cub3d.h

# COLORS
RESET	=	\033[0m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[0;35m
CYAN	=	\033[0;36m

# RULES
all:
	@$(MAKE) mlx
	@$(MAKE) $(PROJECT)
	

$(PROJECT):	$(SRCS) $(UTILS)
	@$(CC)	$(SRCS) $(UTILS) $(MLXLIB) -o $(PROJECT)
	@sleep 	0.321
	@echo	"$(GREEN)$(PROJECT) created$(RESET)"

clean:
	@if [ -f $(PROJECT) ]; then \
		rm -f $(PROJECT); \
		echo "$(RED)$(PROJECT) deleted$(RESET)"; \
	fi

fclean:		clean

norm:
	@norminette $(SRCS) $(UTILS) $(HEADERS)
	
mlx:
	@echo "$(RED)Checking dependecies...$(RESET)"
	@sleep 0.5
	@if ! [ -d /Users/$(USER)/.brew/opt/glfw/lib/ ]; then \
		echo "$(PURPLE)Installing glfw...$(RESET)"; \
		brew install glfw; \
	fi
	@if ! [ -d includes/mlx/build ]; then \
		echo "$(BLUE)Installing mlx...$(RESET)"; \
		cd includes/mlx && cmake -B build; \
	fi
	@if ! [ -e includes/mlx/build/libmlx42.a ]; then \
		echo "$(CYAN)Compiling mlx...$(RESET)"; \
		cd includes/mlx && cmake --build build -j4; \
	fi
	@echo "$(GREEN)Dependencies ok!$(RESET)"

re:			fclean all

.PHONY: all clean fclean re norm mlx
