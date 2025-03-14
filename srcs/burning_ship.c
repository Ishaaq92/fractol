/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:23:30 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/14 12:28:00 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	burning_ship(t_fractol *data, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	c.re = scale(x, -2, 2, WIDTH) * data->zoom + data->x_shift;
	c.im = scale(y, -2, 2, HEIGHT) * data->zoom - data->y_shift;
	z.re = 0;
	z.im = 0;
	i = -1;
	while (++i < ITERATIONS)
	{
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			colour = (i + 1 - log2(log2(fabs(z.re * z.re + z.im * z.im))));
			pixel_put(x, y, data->img, 0x000000 + colour * (0x999999 / ITERATIONS));
			return ;
		}
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		square_complex(&z);
		z.re += c.re;
		z.im += c.im;
	}
	pixel_put(x, y, data->img, PSY_BLACK);
}
