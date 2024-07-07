/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:09:17 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/07 15:09:43 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	bresenham_line(t_point p1, t_point p2, t_data *img)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs((int)p2.x - (int)p1.x);
	dy = abs((int)p2.y - (int)p1.y);
	sx = (p1.x < p2.x) ? 1 : -1;
	sy = (p1.y < p2.y) ? 1 : -1;
	err = dx - dy;

	while (1)
	{
		my_mlx_pixel_put(img, p1.x, p1.y, 0x0000FF00);
		if (p1.x == p2.x && p1.y == p2.y)
			break;
		e2 = err * 2;
		if (e2 > -dy) {
			err -= dy;
			p1.x += sx;
		}
		if (e2 < dx) {
			err += dx;
			p1.y += sy;
		}
	}
}

