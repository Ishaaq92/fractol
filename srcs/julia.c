/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:25:42 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/19 12:38:32 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *data, int x, int y)
{
	t_complex	z;
	int			i;
	int			colour;
	double		log_factor;

	z.re = scale(x, -2, 2, WIDTH) * data->zoom + data->x_shift;
	z.im = scale(y, 2, -2, HEIGHT) * data->zoom + data->y_shift;
	i = -1;
	while (++i < data->iterations)
	{
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			log_factor = log(i + 1) / log(data->iterations + 1);
			colour = scale(pow(log_factor, 0.55), data->pallette, PSY_WHITE, 1);
			return (pixel_put(x, y, data->img, colour));
		}
		square_complex(&z);
		z.re += data->c->re;
		z.im += data->c->im;
	}
	pixel_put(x, y, data->img, data->pallette);
}
