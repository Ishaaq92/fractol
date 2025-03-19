/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:34:20 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/19 12:37:58 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *data, int x, int y)
{
	t_complex	z;
	int			i;
	int			colour;
	double		log_factor;

	data->c->re = scale(x, -2, 2, WIDTH) * data->zoom + data->x_shift;
	data->c->im = scale(y, 2, -2, HEIGHT) * data->zoom + data->y_shift;
	z.re = 0;
	z.im = 0;
	i = -1;
	while (++i < data->iterations)
	{
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			log_factor = log(i + 1) / log(data->iterations + 1);
			colour = scale(log_factor, PSY_BLACK, data->pallette, 1.0);
			return (pixel_put(x, y, data->img, colour));
		}
		square_complex(&z);
		z.re = z.re + data->c->re;
		z.im = z.im + data->c->im;
	}
	pixel_put(x, y, data->img, data->pallette);
}
