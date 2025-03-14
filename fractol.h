/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:44:56 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/14 11:39:56 by isahmed          ###   ########.fr       */
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

# define PSY_RED        0xFF2079  // Vibrant Pinkish-Red
# define PSY_ORANGE     0xFF7300  // Electric Orange
# define PSY_YELLOW     0xF6F402  // Neon Yellow
# define PSY_GREEN      0x00FF66  // Cyber Green
# define PSY_CYAN       0x00F0FF  // Electric Cyan
# define PSY_BLUE       0x2900FF  // Deep Neon Blue
# define PSY_PURPLE     0x8D00FF  // Psychedelic Purple
# define PSY_MAGENTA    0xFF00FF  // Hot Magenta
# define PSY_TEAL       0x00F9DE  // Bright Teal
# define PSY_PINK       0xFF1493  // Deep Neon Pink
# define PSY_LIME       0xCCFF00  // Acid Lime
# define PSY_VIOLET     0x9400D3  // Deep Violet
# define PSY_INDIGO     0x4B0082  // Indigo Trippy Tone
# define PSY_GOLD       0xFFD700  // Metallic Psychedelic Gold
# define PSY_WHITE      0xFFFFFF  // Pure White
# define PSY_BLACK      0x000000  // Deep Black

enum e_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
};

typedef struct t_img
{
	void	*img;
	char	*pxls;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;


typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_img		*img;
	enum e_type	type;
	t_complex	*c;
	double		zoom;
	double		x_shift;
	double		y_shift;
}	t_fractol;

// mandelbrot.c
void	mandelbrot(t_fractol *data, int x, int y);
void	render(t_fractol *data);

// julia.c
int		input(int keysym, t_fractol *data);
int		scroll_with_cursor(int keysym, int x, int y, t_fractol *data);

// burning_ship.c
void	burning_ship(t_fractol *data, int x, int y);

// utils.c
double	scale(double u, double new_min, double new_max, double old_max);
void	ft_quit(t_fractol *data);
int		destrory(t_fractol *data);
void	square_complex(t_complex *z);

// utils2.c
double	ft_atod(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// fractol.c
void	fractol_init(t_fractol *data);
void	pixel_put(int x, int y, t_img *img, int colour);
void	julia(t_fractol *data, int x, int y);

#endif
