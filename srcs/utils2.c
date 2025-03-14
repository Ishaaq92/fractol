/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:30:21 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/14 14:45:10 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *nptr)
{
	int		i;
	int		sign;
	double	total;
	double	power;

	i = 0;
	sign = 1;
	total = 0;
	power = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i ++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = sign * -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
		total = (total * 10) + (nptr[i++] - 48);
	if (nptr[i] == '.')
		i ++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		power /= 10;
		total = total + power * (nptr[i++] - 48);
	}
	return (sign * total);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

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
		data->pallette = red;
	else if (keysym == XK_2)
		data->pallette = blue;
	else if (keysym == XK_3)
		data->pallette = green;
	render(data);
	return (0);
}
