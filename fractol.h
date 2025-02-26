/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:44:56 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/26 18:30:29 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800
# define ITERATIONS 100 

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
}	t_fractol;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

void	render(t_fractol *data);
void    fractol_init(t_fractol *data);

#endif
