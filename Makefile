CC = GCC

CFLAGS = -Wall -Wextra -Werror

INCLUDES = solong.h

NAME = solong.a

SOURCES = main.c map.c

OBJECTS = $(SOURCES:.c=.o)

LIBFT_PATH = ./libft/
MLX_PATH = ./minilibx/

all: subsystem $(NAME)

subsystem :
	make -C ./libft
	cp ./libft/libft.a libft.a
	make -C ./minilibx
	cp ./minilibx/libmlx.a libmlx.a

$(NAME): subsystem $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) libft.a libmlx.a -framework OpenGL -framework AppKit -o so_long

bonus: all

clean:
	rm -f $(OBJECTS)
	rm -f $(LIBFT_PATH)*.o
	rm -f $(MLX_PATH)*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_PATH)libft.a
	rm -f $(MLX_PATH)libmlx.a
	rm -f libft.a libmlx.a
	rm -f so_long

re: fclean all
