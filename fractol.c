/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:05:53 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/06 14:28:09 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	data->img.pxls = mlx_get_data_addr(data->img.img, &data->img.bpp, 
								&data->img.line_length,
								&data->img.endian);
	data->zoom = 1.0;
	data->x_shift = 0.0;
	data->y_shift = 0.0;
}

void	pixel_put(int x, int y, t_img *img, int colour)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = img->pxls + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)pixel = colour;
	}
}

int	main(int ac, char *av[])
{
	t_fractol	data;

	if (!ft_strncmp(av[1], "mandelbrot", 10) && ac == 2)
		if (!ft_strncmp(av[1], "julia", 5))
			return (1);
	fractol_init(&data);
	if (av[1][0] == 'm')
	{
		render_mandelbrot(&data);
		mlx_mouse_hook(data.win, scroll_mandelbrot, &data);
		mlx_hook(data.win, KeyPress, KeyPressMask, input_mandelbrot, &data);
	}
	else
	{
		render_julia(&data);
		mlx_mouse_hook(data.win, scroll_julia, &data);
		mlx_hook(data.win, KeyPress, KeyPressMask, input_julia, &data);
	}

	mlx_hook(data.win, 17, KeyPressMask, destrory, &data);
	mlx_loop(data.mlx);
}
