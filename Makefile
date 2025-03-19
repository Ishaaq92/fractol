# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 16:42:19 by isahmed           #+#    #+#              #
#    Updated: 2025/03/19 13:27:04 by isahmed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Iminilibx-linux -I.
CC = gcc
ODIR = objs
SDIR = srcs

VPATH = $(SDIR)

BINARY = fractol
CFILES = mandelbrot.c julia.c fractol.c utils.c utils2.c burning_ship.c
OBJECTS = $(CFILES:%.c=$(ODIR)/%.o)
OBJS := $(patsubst %.c,$(ODIR)/%.o, $(CFILES))
FT_PRINTF = ft_printf/libftprintf.a
$(info $(OBJS))
all: $(BINARY)

DIRS = $(ODIR)

$(DIRS):
	@mkdir -p $@

$(BINARY): $(OBJS) $(FT_PRINTF) 
	$(CC) $(CFLAGS) $^ -o $@ -Lminilibx-linux -lmlx -lX11 -lXext -lm

$(ODIR)/%.o: %.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@
$(FT_PRINTF):
	@make --no-print-directory -C ft_printf

clean:
	rm -rf $(ODIR)

fclean: clean
	make -C ft_printf fclean
	rm -rf $(BINARY)
	rm -rf $(ODIR)

re: fclean all

.PHONY: all clean fclean re

