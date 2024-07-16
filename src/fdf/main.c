/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:16:33 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 22:50:44 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

void	draw_map_to_img(float scale, t_map *map, t_data *img)
{
	int		x;
	int		y;
	int		i;
	t_line	*row;
	t_point	*point;
	t_point	*y_point;

	row = map->matrix;
	y = 0;
	while (row)
	{
		x = 0;
		point = row->line;
		while (point)
		{
			if (row->next != NULL)
			{
				y_point = row->next->line;
				i = x;
				while (i--)
					y_point = y_point->next;
			}
			if (point->next != NULL && row->next != NULL)
			{
				bresenham_line(scale, *point, *(point->next), img);
				bresenham_line(scale, *y_point, *point, img);
			}
			point = point->next;
			x++;
		}
		row = row->next;
		y++;
	}
}

int	close_window(t_vars *vars)
{
	if (vars->img_data.img != NULL)
		mlx_destroy_image(vars->mlx, vars->img_data.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		close_window(vars);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars		vars;
	t_map		*map;
	float		scale;
	int			width;

	map = open_file(argc, argv);
	if (map == NULL)
		return (EXIT_FAILURE);
	width = (0.866025 * (map->row - 1)) - (0.866025 * -(map->column - 1));
	scale = 1.0;
	while (width * scale <= 500)
		scale += 0.5;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (EXIT_FAILURE);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "seong-ki's fdf");
	if (vars.win == NULL)
		return (free(vars.mlx), EXIT_FAILURE);
	vars.img_data.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img_data.addr = mlx_get_data_addr(vars.img_data.img, \
		&vars.img_data.bits_per_pixel, &vars.img_data.line_length, \
		&vars.img_data.endian);
	draw_map_to_img(scale, map, &vars.img_data);
	ft_free_map(map);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img_data.img, 0, 0);
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
