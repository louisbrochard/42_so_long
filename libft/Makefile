NAME		=	libft.a

CC			=	clang

CFILE		=	ft_atoi.c		\
				ft_isdigit.c	\
				ft_itoa.c		\
				ft_putchar.c	\
				ft_putstr.c		\
				ft_split.c		\
				ft_strchr.c		\
				ft_strdup.c		\
				ft_strjoin.c	\
				ft_strlen.c		\
				ft_strncpy.c	\
				ft_gnl.c		\
				ft_calloc.c 	\
				ft_bzero.c 		\
				ft_printf.c ft_print_char.c ft_print_nbr.c ft_print_str.c ft_print_unsigned.c ft_print_hexa.c ft_print_ptr.c \

CFILE_DIR		=	./src/

SRC				=	$(addprefix $(CFILE_DIR), $(CFILE))

INCLUDE_DIR		=	./includes/

FLAG			=	-Wall -Wextra -Werror -g

INCLUDE			=	libft.h

OBJ				=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
