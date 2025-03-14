# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 16:42:19 by isahmed           #+#    #+#              #
#    Updated: 2025/03/14 15:01:08 by isahmed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Iminilibx-linux -g -I.
CC = gcc
ODIR = objs
SDIR = srcs

VPATH = $(SDIR)

BINARY = fractol
CFILES = mandelbrot.c julia.c fractol.c utils.c utils2.c burning_ship.c colours.c
OBJECTS = $(CFILES:%.c=$(ODIR)/%.o)
OBJS := $(patsubst %.c,$(ODIR)/%.o, $(CFILES))

$(info $(OBJS))
all: $(BINARY)

DIRS = $(ODIR)

$(DIRS):
	@mkdir -p $@

$(BINARY): $(OBJS) 
	$(CC) $(CFLAGS) $^ -o $@ -Lminilibx-linux -lmlx -lX11 -lXext -lm

$(ODIR)/%.o: %.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -rf $(BINARY)

re: fclean all

.PHONY: all clean fclean re

