/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:25:42 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/14 13:52:49 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *data, int x, int y)
{
	t_complex	z;
	int			i;
	int			colour;

	z.re = scale(x, -2, 2, WIDTH) * data->zoom + data->x_shift;
	z.im = scale(y, 2, -2, HEIGHT) * data->zoom + data->y_shift;
	i = -1;
	while (++i < ITERATIONS)
	{
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			colour = (i + 1 - log2(log2(fabs(z.re * z.re + z.im * z.im))));
			pixel_put(x, y, data->img, 0x000000
				+ colour * (0x999999 / ITERATIONS));
			return ;
		}
		square_complex(&z);
		z.re += data->c->re;
		z.im += data->c->im;
	}
	pixel_put(x, y, data->img, PSY_PURPLE);
}
