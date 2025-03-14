/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:34:20 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/14 15:13:19 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *data, int x, int y)
{
	t_complex	z;
	int			i;
	int			colour;
	double		smooth_i;

	data->c->re = scale(x, -2, 2, WIDTH) * data->zoom + data->x_shift;
	data->c->im = scale(y, 2, -2, HEIGHT) * data->zoom + data->y_shift;
	z.re = 0;
	z.im = 0;
	i = -1;
	while (++i < ITERATIONS)
	{
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			smooth_i = i + 1 - log2(log2(fabs(z.re * z.im)));
			colour = generate_color(smooth_i / ITERATIONS);
			pixel_put(x, y, data->img, colour);
			return ;
		}
		square_complex(&z);
		z.re = z.re + data->c->re;
		z.im = z.im + data->c->im;
	}
	pixel_put(x, y, data->img, PSY_WHITE);
}

void	render(t_fractol *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (data->type == MANDELBROT)
				mandelbrot(data, x, y);
			else if (data->type == JULIA)
				julia(data, x, y);
			else
				burning_ship(data, x, y);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
