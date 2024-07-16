/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:09:17 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 19:43:23 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

typedef struct s_bresenham
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	p1_color;
	int	p2_color;
}	t_bresenham;

t_bresenham	create_bresenham(t_point p1, t_point p2)
{
	t_bresenham	bresen;

	bresen.x1 = (int) p1.x;
	bresen.y1 = (int) p1.y;
	bresen.x2 = (int) p2.x;
	bresen.y2 = (int) p2.y;
	bresen.dx = abs(bresen.x2 - bresen.x1);
	bresen.dy = -abs(bresen.y2 - bresen.y1);
	bresen.sx = (bresen.x1 < bresen.x2) ? 1 : -1;
	bresen.sy = (bresen.y1 < bresen.y2) ? 1 : -1;
	bresen.err = bresen.dx + bresen.dy;
	bresen.p1_color = p1.color;
	bresen.p2_color = p2.color;
	return (bresen);
}

void	bresenham_line(t_point p1, t_point p2, t_data *img)
{
	t_bresenham	bres;
	int			e2;

	bres = create_bresenham(p1, p2);
	printf("%x %d\n", bres.p1_color, bres.p2_color);
	while (1)
	{
		int color = ft_gradient(bres.p1_color, bres.p2_color, ft_percent(p1.x, p2.x, bres.x1));
		my_mlx_pixel_put(img, bres.x1, bres.y1, color);
		printf("%X\n", color);
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
