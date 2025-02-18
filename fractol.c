#include "fractol.h"

void    fractol_init(t_fractol *data)
{
	data.mlx = mlx_init();
	if (!data.mlx)
		exit(1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	if (!data.win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	data->img->pxls = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.pxls)
	{
		mlx_destoy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	img.pxls = mlx_get_data_addr(img.img, &img.bpp, 
								&img.line_length,
								&img.endian);

}

void	render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < WIDTH)
	{
		x = 0;
		while (x++ < HEIGHT)
		{
			 
		}
	}
}