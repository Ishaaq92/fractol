/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:34:20 by isahmed           #+#    #+#             */
/*   Updated: 2025/02/11 18:33:23 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

typedef struct	t_img {
	void	*img;
	char	*pxls;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	*img;	
}	t_fractol;

void	colour(t_fractol *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, color);
			x ++;
		}
		y ++;
	}

}

int	f(int keysym , t_fractol *data)
{
	if (keysym == XK_r)
	{
		colour(data, 0xff0000);
	}
	if (keysym == XK_g)
	{
		colour(data, 0x00ff00);
	}
	if (keysym == XK_b)
	{
		colour(data, 0x0000ff);
	}
	return (1);
}
int	main(void)
{
	t_fractol	data;
	t_img		img;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hello world!");

	data.img = &img;
	img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	img.pxls = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
								&img.endian);
	mlx_key_hook(data.win, f, &data);	
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(data.mlx);
}
