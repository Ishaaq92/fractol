/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:23:30 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/12 17:29:45 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	burning_ship(t_fractol *data, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	c.re = scale(x, -2 , 2, WIDTH) * data->zoom + data->x_shift;
	c.im = scale(y, 2 , -2, HEIGHT) * data->zoom + data->y_shift;
	z.re = 0;
	z.im = 0;
	if (c.re < 0)
		c.re = -c.re;
	if (c.im < 0)
		c.im = -c.im;
	i = 0;
	while (i < ITERATIONS)
	{
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			colour = PSY_INDIGO + (i * (0xFFFFFF / ITERATIONS));
			pixel_put(x, y, data->img, colour);
			return ;
		}
		square_complex(&z);
		z.re = z.re + c.re;
		z.im = z.im + c.im;
		i ++;
	}
	pixel_put(x, y, data->img, PSY_MAGENTA);
}
