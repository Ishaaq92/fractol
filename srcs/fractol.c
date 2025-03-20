/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:05:53 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/20 14:08:30 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *data, double re, double im)
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
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img->img)
		ft_quit(data);
	data->img->pxls = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->line_length,
			&data->img->endian);
	data->zoom = 1.0;
	data->x_shift = 0.0;
	data->y_shift = 0.0;
	data->c->re = re;
	data->c->im = im;
	data->pallette = BLUE;
	data->iterations = 75;
}

void	render(t_fractol *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (data->type == MANDELBROT)
				mandelbrot(data, x * 17 % WIDTH, y * 17 % HEIGHT);
			else if (data->type == JULIA)
				julia(data, x * 17 % WIDTH, y * 17 % HEIGHT);
			else if (data->type == BURNING_SHIP)
				burning_ship(data, x * 17 % WIDTH, y * 17 % HEIGHT);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

int	main(int ac, char *av[])
{
	t_fractol	data;
	t_img		img;
	t_complex	c;

	data.img = &img;
	data.c = &c;
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
		data.type = MANDELBROT;
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
		data.type = JULIA;
	else if (ac == 2 && ft_strncmp(av[1], "burning", 1) == 0)
		data.type = BURNING_SHIP;
	else
		display_info();
	if (ac == 4)
		fractol_init(&data, ft_atod(av[2]), ft_atod(av[3]));
	else
		fractol_init(&data, 0, 0);
	instructions();
	render(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, input, &data);
	mlx_mouse_hook(data.win, scroll_with_cursor, &data);
	mlx_hook(data.win, 17, KeyPressMask, destrory, &data);
	mlx_loop(data.mlx);
}
