/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_interpolate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:50:16 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 22:48:28 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	ft_percent(int start, int end, int current)
{
	double	dist_2;
	double	distance;

	dist_2 = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (dist_2 / distance);
}

static int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

static int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

static int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	ft_gradient(int start, int end, double percent)
{
	int		new[4];

	new[0] = (int)round((1 - percent) * get_r(start) + percent * get_r(end));
	new[1] = (int)round((1 - percent) * get_g(start) + percent * get_g(end));
	new[2] = (int)round((1 - percent) * get_b(start) + percent * get_b(end));
	return (new[0] << 16 | new[1] << 8 | new[2]);
}
