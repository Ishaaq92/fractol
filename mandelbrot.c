/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaaq <ishaaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:34:20 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/17 16:28:54 by ishaaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_quit(t_fractol *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1); // remove later
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		char	*pixel;

		pixel = img->pxls + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

void	colour(t_fractol *data, int color)
{
	int	x;
	
	y = 0;
	int	y;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(data->img, x, y, color);
			x ++;
		}
		y ++;
	}
}

int	f(int keysym , t_fractol *data)
{
	if (keysym == XK_r)
		colour(data, 0xff0000);
	if (keysym == XK_g)
		colour(data, 0x00ff00);
	if (keysym == XK_b)
		colour(data, 0x0000ff);
	if (keysym == XK_Escape)
		ft_quit(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_fractol	data;
	t_img		img;

	if (av[1] != "mandelbrot" || ac != 2)
		return (1);

	fractol_init(&data);

	fractol_render(&data);
	// mlx_key_hook(data.win, f, &data);	
	mlx_loop(data.mlx);
}
