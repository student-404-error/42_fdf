/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:09:17 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/13 21:01:23 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

#define SCAILING 2;

void	draw_line(t_point p1, t_point p2, t_data *img)
{
	float	a;
	float	b;
	float	dx;
	float	dy;

	p1.x *= SCAILING;
	p1.y *= SCAILING;
	p2.x *= SCAILING;
	p2.y *= SCAILING;
	p1.x += WIDTH / 3;
	p1.y += HEIGHT / 3;
	p2.x += WIDTH / 3;
	p2.y += HEIGHT / 3;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	a = dy / dx;
	b = (p1.y - a * p1.x);

	while (1)
	{
		if (p1.x > p2.x || p1.y > p2.y)
			break ;
		my_mlx_pixel_put(img, p1.x, p1.y, 0x0000FF00);
		p1.x++;
		p1.y = a * p1.x + b;
	}
}

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
	
	p1.x *= SCAILING;
	p1.y *= SCAILING;
	p2.x *= SCAILING;
	p2.y *= SCAILING;
	p1.x += WIDTH / 3;
	p1.y += HEIGHT / 3;
	p2.x += WIDTH / 3;
	p2.y += HEIGHT / 3;
	x = (int)p1.x;
	y = (int)p1.y;
	dx = abs((int)p2.x - x);
	dy = -abs((int)p2.y - y);
	sx = (x < p2.x) ? 1 : -1;
	sy = (y < p2.y) ? 1 : -1;
	err = dx + dy;
	printf("start: (%4f %4f)\n", p1.x, p1.y);
	printf("target: (%4f %4f)\n", p2.x, p2.y);
	printf("%3d %3d %3d %3d %4d\n", dx, dy, sx, sy, err);
	printf(" x   y   err\n");
	while (1)
	{
		printf("%3d %3d", x, y);
		my_mlx_pixel_put(img, x, y, 0x0000FF00);
		if (x == (int)p2.x && y == (int)p2.y)
			break;
		e2 = err * 2;
		printf(" %3d\n", e2);
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
