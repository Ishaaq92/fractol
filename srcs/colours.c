/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:41:40 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/14 15:12:07 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// int	set_colour(t_fractol *data)
// {
// 	if (data->pallette == blue)
// 	{
// 		return (0x000000 + 0x0000ff * (0x999999 / ITERATIONS));
// 	}
// 	else if (data->pallette == red)
// 	{
// 		return (0x000000 + 0xff0000 * (0x999999 / ITERATIONS));
// 	}
// 	else if (data->pallette == green)
// 	{
// 		return (0x000000 + 0x00ff00 * (0x999999 / ITERATIONS));
// 	}
// }

static void	hue_to_rgb(double hue, int *r, int *g, int *b)
{
	double	x = 1 - fabs(fmod(hue / 60.0, 2) - 1);
	if (hue < 60) { *r = 255; *g = x * 255; *b = 0; }
	else if (hue < 120) { *r = x * 255; *g = 255; *b = 0; }
	else if (hue < 180) { *r = 0; *g = 255; *b = x * 255; }
	else if (hue < 240) { *r = 0; *g = x * 255; *b = 255; }
	else if (hue < 300) { *r = x * 255; *g = 0; *b = 255; }
	else { *r = 255; *g = 0; *b = x * 255; }
}

int	generate_color(double t)
{
	int	r, g, b;
	double	hue;

	hue = 360.0 * t; // Map `t` to a hue angle (0-360°)
	hue_to_rgb(hue, &r, &g, &b);
	return ((r << 16) | (g << 8) | b);
}
