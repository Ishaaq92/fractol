/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:05:53 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/18 15:40:14 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double unscaled_num, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min;
}

void    fractol_init(t_fractol *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	data->img.pxls = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.pxls)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	
	data->img.pxls = mlx_get_data_addr(data->img.img, &data->img.bpp, 
								&data->img.line_length,
								&data->img.endian);

}

void	pixel_put(int x, int y, t_img *img, int colour)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) // Ensure pixel is within bounds
	{
		char	*pixel;

		pixel = img->pxls + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)pixel = colour;
	}
}

void	handle_pixel(t_fractol *data, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	z.re = 0.0;
	z.im = 0.0;
	c.re = scale(x, -2 , 2, WIDTH);
	c.im = scale(y, 2 , -2, HEIGHT);

	i = 0;
	while (i < 24)
	{
		z.re = (z.re * z.re) - (z.im * z.im);
		z.im = 2 * (z.im * z.re);
		
		z.re = z.re + c.re;
		z.im = z.im + c.im;
		if ((z.re * z.re) + (z.im * z.im) > 4)
		{
			colour = scale(i, BLACK, WHITE, 24);
			pixel_put(x, y, &data->img, colour);
			return ;
		}
		pixel_put(x, y, &data->img, BLACK);
	}

}


void	render(t_fractol *data)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < WIDTH)
	{
		x = 0;
		while (x++ < HEIGHT)
		{
			handle_pixel(data, x, y);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
