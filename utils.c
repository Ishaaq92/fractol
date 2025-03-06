/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:19:35 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/05 14:32:16 by isahmed          ###   ########.fr       */
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

double	scale(double unscaled_num, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * (unscaled_num - 0) / (old_max - 0) + new_min;
}

int	destrory(t_fractol *data)
{
	ft_quit(data);
    return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

void	square_complex(t_complex *z)
{
	double	temp;

	temp = z->re;
	z->re = (z->re * z->re) - (z->im * z->im);
	z->im = 2 * (z->im * temp);
}