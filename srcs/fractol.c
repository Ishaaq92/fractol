/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:05:53 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/11 15:08:04 by isahmed          ###   ########.fr       */
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
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img->img)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	data->img->pxls = mlx_get_data_addr(data->img->img, &data->img->bpp, 
								&data->img->line_length,
								&data->img->endian);
	data->zoom = 1.0;
	data->x_shift = 0.0;
	data->y_shift = 0.0;
	data->c->re = 0;
	data->c->im = 0;
	data->strength_x = 1;
	data->strength_y = 1;

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

int	check_args(t_fractol *data, int ac, char *av[])
{
	if (ac != 4)
		ft_quit(data);
	return (1);
	// 	while (av[++i] != 0)
	// {
	// 	if (is_empty(av[i]) == -1)
	// 		free_ll(data, 1);
	// 	j = 0;
	// 	while (av[i][j] != '\0')
	// 	{
	// 		skip_white_space(av, i, &j);
	// 		if (!(av[i][j] >= '0' && av[i][j] <= '9'))
	// 			if ((av[i][j] != '+' && av[i][j] != '-') ||
	// 			!(av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
	// 				free_ll(data, 1);
	// 		append_node(data->stack_a, ft_atoi(data, &av[i][j], &j));
	// 		if (!(av[i][j] >= 9 && av[i][j] <= 13) &&
	// 		(av[i][j] != ' ') && av[i][j] != '\0')
	// 			free_ll(data, 1);
	// 		skip_white_space(av, i, &j);
	// 	}
	// }
}

int	main(int ac, char *av[])
{
	t_fractol	data;
	t_complex	c;
	t_img		img;

	data.img = &img;
	data.c = &c;
	fractol_init(&data);
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0 && ac == 2)
	{
		render_mandelbrot(&data);
		mlx_mouse_hook(data.win, scroll_mandelbrot, &data);
		mlx_hook(data.win, KeyPress, KeyPressMask, input_mandelbrot, &data);
	}
	else if (ft_strncmp(av[1], "julia", 5) == 0 &&  ac == 4 && check_args(&data, ac, av))
	{
		c.re = ft_atod(av[2]);
		c.im = ft_atod(av[3]);
		render_julia(&data);
		mlx_mouse_hook(data.win, scroll_julia, &data);
		mlx_hook(data.win, KeyPress, KeyPressMask, input_julia, &data);
	}
	else
		ft_quit(&data);
	mlx_hook(data.win, 17, KeyPressMask, destrory, &data);
	mlx_loop(data.mlx);
}
