/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:09:17 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/14 21:39:38 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

void	bresenham_line(t_point p1, t_point p2, t_data *img)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	x = (int)p1.x;
	y = (int)p1.y;
	dx = abs((int)p2.x - x);
	dy = -abs((int)p2.y - y);
	sx = (x < p2.x) ? 1 : -1;
	sy = (y < p2.y) ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		my_mlx_pixel_put(img, x, y, p1.color);
		if (x == (int)p2.x && y == (int)p2.y)
			break ;
		e2 = err * 2;
		if (e2 >= dy)
		{
			err += dy;
			x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y += sy;
		}
	}
}
