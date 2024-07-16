/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:09:17 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 23:39:01 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "algorithm.h"
#include <stdio.h>

t_bresenham	create_bresenham(float scale, t_point p1, t_point p2)
{
	t_bresenham	bresen;

	bresen.x1 = (int)(p1.x * scale) + 960;
	bresen.y1 = (int)(p1.y * scale) + 400;
	bresen.x2 = (int)(p2.x * scale) + 960;
	bresen.y2 = (int)(p2.y * scale) + 400;
	bresen.dx = abs(bresen.x2 - bresen.x1);
	bresen.dy = -abs(bresen.y2 - bresen.y1);
	bresen.sx = MAX_FLAG(bresen.x1, bresen.x2);
	bresen.sy = MAX_FLAG(bresen.y1, bresen.y2);
	bresen.err = bresen.dx + bresen.dy;
	bresen.p1_color = p1.color;
	bresen.p2_color = p2.color;
	return (bresen);
}

void	draw_line(float scale, t_point p1, t_point p2, t_data *img)
{
	t_bresenham	bres;
	int			e2;
	int			start;

	bres = create_bresenham(scale, p1, p2);
	start = bres.x1;
	while (1)
	{
		my_mlx_pixel_put(img, bres.x1, bres.y1, ft_gradient(bres.p1_color, \
		bres.p2_color, ft_percent(start, bres.x2, bres.x1)));
		if (bres.x1 == bres.x2 && bres.y1 == bres.y2)
			break ;
		e2 = bres.err * 2;
		if (e2 >= bres.dy)
		{
			bres.err += bres.dy;
			bres.x1 += bres.sx;
		}
		if (e2 <= bres.dx)
		{
			bres.err += bres.dx;
			bres.y1 += bres.sy;
		}
	}
}
