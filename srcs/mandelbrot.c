/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:34:20 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/12 16:17:35 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *data, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	c.re = scale(x, -2 , 2, WIDTH) * data->zoom + data->x_shift;
	c.im = scale(y, 2 , -2, HEIGHT) * data->zoom + data->y_shift;
	z.re = 0;
	z.im = 0;
	i = 0;
	while (i < ITERATIONS)
	{
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			colour = PSY_BLACK + (i * (0xFFFFFF / ITERATIONS));
			pixel_put(x, y, data->img, colour);
			return ;
		}
		square_complex(&z);
		z.re = z.re + c.re;
		z.im = z.im + c.im;
		i ++;
	}
	pixel_put(x, y, data->img, PSY_GOLD);
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
			else
				julia(data, x, y);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
