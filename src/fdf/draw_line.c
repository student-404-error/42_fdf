/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:09:17 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/12 02:12:51 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

#define SCAILING 3;

void	bresenham_line(t_point p1, t_point p2, t_data *img)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	
	p1.x *= SCAILING;
	p1.y *= SCAILING;
	p2.x *= SCAILING;
	p2.y *= SCAILING;
	p1.x += WIDTH / 3;
	p1.y += HEIGHT / 3;
	p2.x += WIDTH / 3;
	p2.y += HEIGHT / 3;
	dx = abs((int)p2.x - (int)p1.x);
	dy = abs((int)p2.y - (int)p1.y);
	sx = (p1.x < p2.x) ? 1 : -1;
	sy = (p1.y < p2.y) ? 1 : -1;
	err = dx - dy;
	printf("%d %d %d %d %d %f\n", dx, dy, sx, sy, err, p1.x);
	printf("%f %f %f %f\n", p1.x, p1.y, p2.x, p2.y);
	while (1)
	{
	printf("%f %f %f %f\n", p1.x, p1.y, p2.x, p2.y);
		my_mlx_pixel_put(img, p1.x, p1.y, 0x0000FF00);
		if (p1.x > p2.x || p1.y > p2.y)
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

