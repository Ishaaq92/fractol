/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:23:30 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/19 12:37:17 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	burning_ship(t_fractol *data, int x, int y)
{
	t_complex	z;
	int			i;
	int			colour;
	double		log_factor;

	data->c->re = scale(x, -2, 2, WIDTH) * data->zoom + data->x_shift;
	data->c->im = scale(y, -2, 2, HEIGHT) * data->zoom - data->y_shift;
	z.re = 0;
	z.im = 0;
	i = -1;
	while (++i < data->iterations)
	{
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			log_factor = log(1 + i) / log(1 + data->iterations);
			colour = scale(pow(log_factor, 0.55), PSY_BLACK, data->pallette, 1);
			return (pixel_put(x, y, data->img, colour));
		}
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		square_complex(&z);
		z.re += data->c->re;
		z.im += data->c->im;
	}
	pixel_put(x, y, data->img, data->pallette);
}
