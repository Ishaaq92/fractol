/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:34:20 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/11 13:59:05 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot(t_fractol *data, int x, int y)
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

void	render_mandelbrot(t_fractol *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot(data, x, y);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

int	input_mandelbrot(int keysym, t_fractol *data)
{
	if (keysym == XK_Escape)
		ft_quit(data);
	else if (keysym == XK_a || keysym == XK_Left)
		data->x_shift -= (data->zoom/2 * 0.35);
	else if (keysym == XK_d || keysym == XK_Right)
		data->x_shift += (data->zoom/2 * 0.35);
	else if (keysym == XK_w || keysym == XK_Up)
		data->y_shift += (data->zoom/2 * 0.35);
	else if (keysym == XK_s || keysym == XK_Down)
		data->y_shift -= (data->zoom/2 * 0.35);
	render_mandelbrot(data);
	return (1);
}

int	scroll_mandelbrot(int keysym, int x, int y, t_fractol *data)
{
	(void) x;
	(void) y;

	if (!data)
		return (1);
	if (keysym == 4)
		data->zoom *= 0.9;
	if (keysym == 5)
		data->zoom /= 0.9;
	render_mandelbrot(data);
	return (0);
}

