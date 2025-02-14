CC = cc

# CFLAGS = -Wall -Wextra -Werror

SRC = fractol.c

OBJ = $(SRC:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re