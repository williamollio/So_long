CC = GCC

CFLAGS = -Wall -Wextra -Werror -c

INCLUDES = solong.h

NAME = solong.a

SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:.c=.o)

MAKE = make

LIBFT_PATH = ./libft/

all: subsystem $(NAME)

subsystem :
	$(MAKE) -C libft

$(NAME): $(OBJECTS)
	ar cr $@ $(OBJECTS) $(LIBFT_PATH)*.o

bonus: all

clean:
	rm -f $(OBJECTS) $(LIBFT_PATH)*.o

fclean: clean
	rm -f $(NAME) $(LIBFT_PATH)libft.a

re: fclean all
