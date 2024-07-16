/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:16:33 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 23:46:13 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

void	ft_draw(float scale, t_line *row, t_data *img)
{
	int		x;
	int		i;
	t_point	*y_point;
	t_point	*point;

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
			draw_line(scale, *point, *(point->next), img);
			draw_line(scale, *y_point, *point, img);
		}
		point = point->next;
		x++;
	}
}

void	draw_map_to_img(float scale, t_map *map, t_data *img)
{
	t_line	*row;

	row = map->matrix;
	while (row)
	{
		ft_draw(scale, row, img);
		row = row->next;
	}
}

float	fit_scale(int width)
{
	float	scale;

	scale = 1.0;
	while (width * scale <= 300)
		scale += 0.5;
	return (scale);
}

int	main(int argc, char *argv[])
{
	t_vars		vars;
	t_map		*map;
	int			width;

	map = open_file(argc, argv);
	if (map == NULL)
		return (EXIT_FAILURE);
	width = (0.866025 * (map->row - 1)) - (0.866025 * -(map->column - 1));
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
	draw_map_to_img(fit_scale(width), map, &vars.img_data);
	ft_free_map(map);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img_data.img, 0, 0);
	mlx_key_hook(vars.win, key_press, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
