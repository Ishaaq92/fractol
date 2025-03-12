/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:25:42 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/12 15:33:17 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia(t_fractol *data, int x, int y)
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

void	render_julia(t_fractol *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			julia(data, x, y);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

int	input_julia(int keysym, t_fractol *data)
{
	if (keysym == XK_Escape)
		ft_quit(data);
	else if (keysym == XK_a || keysym == XK_Left)
		data->x_shift -= (data->zoom / 2 * 0.35);
	else if (keysym == XK_d || keysym == XK_Right)
		data->x_shift += (data->zoom / 2 * 0.35);
	else if (keysym == XK_w || keysym == XK_Up)
		data->y_shift += (data->zoom / 2 * 0.35);
	else if (keysym == XK_s || keysym == XK_Down)
		data->y_shift -= (data->zoom / 2 * 0.35);
	render_julia(data);
	return (0);
}

int	scroll_julia(int keysym, int x, int y, t_fractol *data)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = scale(x, -2, 2, WIDTH - 1) * data->zoom + data->x_shift;
	mouse_im = scale(y, 2, -2, HEIGHT - 1) * data->zoom + data->y_shift;
	if (keysym == 4)
	{
		data->x_shift = mouse_re + (data->x_shift - mouse_re) * 0.9;
		data->y_shift = mouse_im + (data->y_shift - mouse_im) * 0.9;
		data->zoom *= 0.9;
	}
	if (keysym == 5)
	{
		data->x_shift = mouse_re + (data->x_shift - mouse_re) / 0.9;
		data->y_shift = mouse_im + (data->y_shift - mouse_im) / 0.9;
		data->zoom /= 0.9;
	}
	render_julia(data);
	return (0);
}
