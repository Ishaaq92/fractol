CFLAGS = -Wall -Wextra -Iminilibx-linux
CC = gcc

BINARY = mandelbrot

CFILES = mandelbrot.c fractol.c
OBJECTS = $(CFILES:%.c=%.o)

all: $(BINARY)

$(BINARY): $(OBJECTS) 
	$(CC) $(CFLAGS) $^ -o $@ -Lminilibx-linux -lmlx -lX11 -lXext -lm

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf *.o 
	rm -rf $(BINARY)

re: fclean all

.PHONY: all clean fclean re

