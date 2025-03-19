/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:05:53 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/19 13:54:34 by isahmed          ###   ########.fr       */
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
				mandelbrot(data, x, y);
			else if (data->type == JULIA)
				julia(data, x, y);
			else if (data->type == BURNING_SHIP)
				burning_ship(data, x, y);
			x ++;
		}
		y ++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

void	display_info(void)
{
	ft_printf("Run './fractol'\n\n");
	ft_printf("Followed by one of:\n");
	ft_printf(" - 'mandelbrot'\n");
	ft_printf(" - 'julia <double1> <double2>'\n");
	ft_printf(" - 'burning'\n\n");
	ft_printf("Examples:\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("./fractol julia -0.5 0.5\n");
	ft_printf("./fractol burning\n");
	exit(1);
}

void	instructions(void)
{
	ft_printf("Controls & Bindings\n\n");
	ft_printf("Switching Colours:\n");
	ft_printf("1	- RED\n");
	ft_printf("2	- GREEN\n");
	ft_printf("3	- BLUE\n");
	ft_printf("\n");
	ft_printf("Shifting:\n");
	ft_printf("w	- UP\n");
	ft_printf("a	- LEFT\n");
	ft_printf("s	- DOWN\n");
	ft_printf("d	- RIGHT\n");
	ft_printf("\n");
	ft_printf("Adjust Iterations:\n");
	ft_printf(".	- INCREASE\n");
	ft_printf(",	- DECREASE");
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
