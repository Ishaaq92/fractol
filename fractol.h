/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:44:56 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/06 14:25:27 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800
# define ITERATIONS 75 

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define YELLOW      0xFFFF00
# define CYAN        0x00FFFF
# define MAGENTA     0xFF00FF

typedef struct	t_img {
	void	*img;
	char	*pxls;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;
	double	zoom;
	double	x_shift;
	double	y_shift;
}	t_fractol;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;


// mandelbrot.c
void	render_mandelbrot(t_fractol *data);
int		input_mandelbrot(int keysym, t_fractol *data);
int		scroll_mandelbrot(int keysym, int x, int y, t_fractol *data);

// julia.c
void	render_julia(t_fractol *data);
int		input_julia(int keysym, t_fractol *data);
int		scroll_julia(int keysym, int x, int y, t_fractol *data);

// utils.c
double	scale(double unscaled_num, double new_min, double new_max, double old_max);
void	ft_quit(t_fractol *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		destrory(t_fractol *data);
void	square_complex(t_complex *z);

// fractol.c
void    fractol_init(t_fractol *data);
int		input_mandelbrot(int keysym, t_fractol *data);
void	pixel_put(int x, int y, t_img *img, int colour);

#endif
