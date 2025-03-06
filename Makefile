# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 16:42:19 by isahmed           #+#    #+#              #
#    Updated: 2025/03/06 14:45:43 by isahmed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Iminilibx-linux -g
CC = gcc
ODIR = objs
SDIR = srcs

BINARY = fractol
CFILES = mandelbrot.c julia.c fractol.c utils.c
OBJECTS = $(CFILES:%.c=$(ODIR)/%.o)
OBJS = $(patsubst %.c,$(ODIR)/%.o, $(SDIR)/$(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS) 
	$(CC) $(CFLAGS) $^ -o $@ -Lminilibx-linux -lmlx -lX11 -lXext -lm

$(ODIR)/%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf *.o 
	rm -rf $(BINARY)

re: fclean all

.PHONY: all clean fclean re

