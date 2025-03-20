/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:58:16 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/20 14:08:45 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	scroll_with_cursor(int keysym, int x, int y, t_fractol *data)
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
	render(data);
	return (0);
}

int	input(int keysym, t_fractol *data)
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
	else if (keysym == XK_1)
		data->pallette = RED;
	else if (keysym == XK_2)
		data->pallette = BLUE;
	else if (keysym == XK_3)
		data->pallette = GREEN;
	else if (keysym == XK_period)
		data->iterations += 5;
	else if (keysym == XK_comma)
		data->iterations -= 5;
	render(data);
	return (0);
}
