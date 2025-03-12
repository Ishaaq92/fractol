/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:19:35 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/12 15:32:14 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_quit(t_fractol *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
}

double	scale(double u, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * (u - 0) / (old_max - 0) + new_min;
}


int	destrory(t_fractol *data)
{
	ft_quit(data);
    return (0);
}


void	square_complex(t_complex *z)
{
	double	temp;

	temp = z->re;
	z->re = (z->re * z->re) - (z->im * z->im);
	z->im = 2 * (z->im * temp);
}