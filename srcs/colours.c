/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:41:40 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/14 16:46:03 by isahmed          ###   ########.fr       */
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
	*r = 0;
	*g = 100;
	*b = 255; // Default base color is blue

	if (hue < 50) 
	{ 
		*g = x * 150;  
		*b = 255;
	}
	else if (hue < 120) 
	{
		*g = x * 180;
		*b = 255 - (x * 50);
	}
	else if (hue < 180) 
	{
		*g = x * 120;
		*b = 255 - (x * 80);
	}
	else if (hue < 240) 
	{
		*r = x * 50;
		*g = 50 + (x * 100);
		*b = 200 + (x * 55);
	}
	else 
	{
		*r = x * 100;
		*g = 100 + (x * 80);
	}
}

int	generate_color(double t)
{
	int	r, g, b;
	double	hue;

	hue = 180.0 + (t * 90); // Map `t` to a hue angle (0-360°)
	hue_to_rgb(hue, &r, &g, &b);
	return ((r << 16) | (g << 8) | b);
}
