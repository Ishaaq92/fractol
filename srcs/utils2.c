/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isahmed <isahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:30:21 by isahmed           #+#    #+#             */
/*   Updated: 2025/03/07 14:30:34 by isahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *nptr)
{
	int		i;
	int		sign;
	double  total;
	double		power;

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