/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:16:33 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/12 01:01:17 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

void	draw_map_to_img(t_map *map, t_data *img)
{
	int		x;
	int		y;
	t_line	*row;
	t_point	*point;

	(void)img;
	row = map->matrix;
	y = 0;
	while (row)
	{
		x = 0;
		point = row->line;
		while (point)
		{
			printf("=============================\n");
			printf("%d %d: %f %f\n", x, y, WIDTH / 2 - point->x, HEIGHT / 2 - point->y);
			if (row->next != NULL)
				printf("%d %d: %f %f\n", x, y + 1, WIDTH / 2 - row->next->line->x, HEIGHT / 2 - row->next->line->y);
			if (point->next != NULL)
				printf("%d %d: %f %f\n", x + 1, y, WIDTH / 2 - point->next->x, HEIGHT / 2 - point->next->y);
			if (point->next != NULL && row->next != NULL)
				bresenham_line(*point, *(point->next), img);
			printf("=============================\n");
			point = point->next;
			x++;
		}
		printf("===================\n");
		row = row->next;
		y++;
	}
}

int main(int argc, char *argv[])
{
	t_data		img;
	t_vars		vars;
	t_map	*map;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	map = open_file(argc, argv);
	draw_map_to_img(map, &img);
	printf("hello");
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
