/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:05:53 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/14 14:31:03 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *data)
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
	data->c->re = 0;
	data->c->im = 0;
}

int	main(int ac, char *av[])
{
	t_fractol	data;
	t_img		img;
	t_complex	c;

	data.img = &img;
	data.c = &c;
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0 && ac == 2)
		data.type = MANDELBROT;
	else if (ft_strncmp(av[1], "julia", 5) == 0 && ac == 4)
	{
		data.type = JULIA;
		c.re = ft_atod(av[2]);
		c.im = ft_atod(av[3]);
	}
	else if (ft_strncmp(av[1], "b", 1) == 0 && ac == 2)
		data.type = BURNING_SHIP;
	else
		exit(1);
	fractol_init(&data);
	render(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, input, &data);
	mlx_mouse_hook(data.win, scroll_with_cursor, &data);
	mlx_hook(data.win, 17, KeyPressMask, destrory, &data);
	mlx_loop(data.mlx);
}
