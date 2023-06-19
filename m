#SETUP
NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf

#HEADERS
HEADER_SRCS	=	so_long.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

#MADATORY
MPATH_SRCS	=	so_long.c \
				checker.c \
				gnl.c \
				gnl_utils.c \
				maps.c \
				utils.c \
				move.c \
				graphics.c
MPATH_DIR	=	srcs/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

#MLX
MLX_FILE	=	libmlx.a
MLX_FLAG	=	-lX11 -lXext
MLX_PATH	=	./minilibx-linux/
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

mlx:
	@make -sC $(MLX_PATH)

$(NAME):		mlx $(OBJ_M)
				@$(CC) $(OBJ_M) $(MLX_EX) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_M)
				@make clean -sC $(MLX_PATH)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m