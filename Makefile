NAME = fillit
SRC = srcs/fillit.c srcs/main.c
INCLUDES = includes/fillit.h
OBJ = $(SRCS:.c=.o)


all: $(NAME)

$(NAME):
	@gcc -g -Wall -Wextra -Werror main.c fillit.c -L libft/ -lft -I libft/includes/ -I.

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all