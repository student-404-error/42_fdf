/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_point_and_row.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:02:14 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 23:07:17 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_point	*create_point(int x, int y, int z, char *line)
{
	t_point	*point;

	point = (t_point *) malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = 0.866025 * (x - y);
	point->y = 0.5 * (x + y) - z;
	point->color = get_color(line);
	point->next = NULL;
	return (point);
}

t_line	*create_row(int size, int y, char *line)
{
	int			x;
	char		**points;
	t_line		*row;
	t_point		*pt;

	row = malloc(sizeof(t_line));
	if (!row)
		return (NULL);
	points = ft_split(line, ' ');
	pt = NULL;
	x = 0;
	while (points[x] && points[x][0] != '\n')
	{
		join_point(&pt, create_point(x, y, ft_atoi(points[x]), points[x]));
		x++;
	}
	ft_free_split(points);
	if (size != 0 && size != x)
	{
		printf("Find wrong length!!\n");
		return (free(row), ft_free_points(pt), NULL);
	}
	row->line = pt;
	row->next = NULL;
	return (row);
}
