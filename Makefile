CC = cc

# CFLAGS = -Wall -Wextra -Werror

SRC = fractol.c main.c utils.c errors.c events.c fractol_utils.c calculations.c

SRC_BONUS = bonus/fractol_bonus.c bonus/main.c bonus/utils_bonus.c bonus/errors_bonus.c bonus/events_bonus.c bonus/fractol_utils_bonus.c bonus/calculations_bonus.c bonus/burning_ship_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus