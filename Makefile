NAME = so_long
CFLAGS = -Wall -Wextra -Werror
FLAGS = -lmlx -framework OpenGL -framework AppKit
CC = cc
SRCS = err_checker.c ft_free.c init_game.c libft.c moves.c so_long.c ft_floodfill.c
OBJC = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJC)
	@$(CC) $(FLAGS) $(CFLAGS) $(SRCS) -o so_long
	@echo "so_long is ready"

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJC)
	@echo "objects removed"
fclean:
	@rm  -f $(OBJC) $(NAME)
	@echo "objects and executable removed"
re:	fclean all