/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:23:30 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/14 15:26:01 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	burning_ship(t_fractol *data, int x, int y)
{
	t_complex	z;
	int			i;
	int			colour;
	double		smooth_i;

	data->c->re = scale(x, -2, 2, WIDTH) * data->zoom + data->x_shift;
	data->c->im = scale(y, -2, 2, HEIGHT) * data->zoom - data->y_shift;
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
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		square_complex(&z);
		z.re += data->c->re;
		z.im += data->c->im;
	}
	pixel_put(x, y, data->img, PSY_BLACK);
}
