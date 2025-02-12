#include "fractol.h"

void    fractol_init(t_fractol *data, t_img *img)
{

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	data.img = &img;
	img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	img.pxls = mlx_get_data_addr(img.img, &img.bpp, 
								&img.line_length,
								&img.endian);
}