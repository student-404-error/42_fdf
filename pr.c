/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:27:31 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/13 20:36:30 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void	draw_line(int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;

	dx = abs(x2 - x1);
	dy = -abs(y2 - y1);
	int	sx = x1<x2 ? 1:-1;
	int	sy = y1<y2 ? 1:-1;
	int	err = dx + dy, e2;

	printf(" dx  dy  sx  sy  err\n");
	printf("%3d %3d %3d %3d %4d\n", dx, dy, sx, sy, err);
	printf(" x   y   err\n");
	while (1)
	{
		printf("%3d %3d %3d\n", x1, y1, err);
		if (x1 == x2 && y1 == y2)
			break;
		e2 = 2*err;
		if (e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
		usleep(10000);
	}
}
/*			test cases

	m은 기울기.
	
	m = (y2 - y1) / (x2 - x1)

	1. m < -1
		start(0, 0) ====> end(4, -8)
	2. [-1, 0)
		2-1. start(0, 0) ====> end(4, -4) [ m = -1 ]
		2-2. start(0, 0) ====> end(6, -2) -1과 0사이
	3. (0, 1]
		3-1. start(0, 0) ====> end(4, 4) [ m = 1 ]
		3-2. start(0, 0) ====> end(6, 2) 0과 1사이
	4. m > 1
		start(0, 0) ====> end(6, 10)
	기울기가 0일 땐?
	5. m = 0
		5-1. start(0, 0) ====> end(0, 8) y축과 평행
		5-2. start(0, 0) ====> end(6, 0) x축과 평행
*/

int	main()
{
	printf("============================\n");
	printf("start (0, 0)\n  end (4, -8)\n");
	draw_line(0, 0, 4, -8);
	printf("============================\n");
	printf("start (0, 0)\n  end (4, -4)\n");
	draw_line(0, 0, 4, -4);
	printf("============================\n");
	printf("start (0, 0)\n  end (6, -2)\n");
	draw_line(0, 0, 6, -2);
	printf("============================\n");
	printf("start (0, 0)\n  end (4, 4)\n");
	draw_line(0, 0, 4, 4);
	printf("============================\n");
	printf("start (0, 0)\n  end (6, 2)\n");
	draw_line(0, 0, 6, 2);
	printf("============================\n");
	printf("start (0, 0)\n  end (6, 10)\n");
	draw_line(0, 0, 6, 10);
	printf("============================\n");
	printf("start (0, 0)\n  end (0, 8)\n");
	draw_line(0, 0, 0, 8);
	printf("============================\n");
	printf("start (0, 0)\n  end (6, 0)\n");
	draw_line(0, 0, 6, 0);
	printf("============================\n");
	printf("start (640, 360)\n  end (648, 365)\n");
	draw_line(640, 360, 648, 365);
	// 대박.
}
