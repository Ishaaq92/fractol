/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:30:21 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/19 13:59:22 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *nptr)
{
	int		i;
	int		sign;
	double	total;
	double	power;

	i = 0;
	sign = 1;
	total = 0;
	power = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i ++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = sign * -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
		total = (total * 10) + (nptr[i++] - 48);
	if (nptr[i] == '.')
		i ++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		power /= 10;
		total = total + power * (nptr[i++] - 48);
	}
	return (sign * total);
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
