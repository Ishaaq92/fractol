/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:25:42 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/12 17:09:23 by isahmed          ###   ########.fr       */
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
	i = 0;
	while (i < ITERATIONS)
	{
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			colour = scale(i, 0, PSY_MAGENTA, ITERATIONS);
			pixel_put(x, y, data->img, colour);
			return ;
		}
		square_complex(&z);
		z.re = z.re + (*data->c).re;
		z.im = z.im + (*data->c).im;
		i ++;
	}
	pixel_put(x, y, data->img, PSY_PURPLE);
}

