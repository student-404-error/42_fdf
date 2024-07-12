/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:15:46 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/12 02:05:06 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

/*
float	*get_color(char *line)
{
	char	**color;

	color = ft_split(line, ',');
	if (color[1] == NULL)
	{
		
	}
	
	// color will be 0x-------- or nothing
}
*/

t_point	*create_point(int x, int y, int z/*, char *line*/)
{
	t_point	*point;

	point = (t_point *) malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = /*cos(30 * PI / 180)*/ (0.866025 * (x - y));
	point->y = (sin(30 * PI / 180) * (x + y) - z);
	//point->color = get_color(line);
	point->argb[0] = 256;
	point->argb[1] = 256;
	point->argb[2] = 256;
	point->argb[3] = 256;
	point->next = NULL;
	return (point);
}

void	join_point(t_point **row, t_point *new_point)
{
	t_point	*last_node;

	if (*row == NULL)
		*row = new_point;
	else
	{
		last_node = *row;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_point;
	}
}

void	ft_free_points(t_point *pt)
{
	t_point	*free_point;
	t_point	*tmp_point;

	free_point = pt;
	while (free_point)
	{
		tmp_point = free_point->next;
		free(free_point);
		free_point = tmp_point;
	}
}

t_line	*create_row(int y, char *line)
{
	int			x;
	char		**points;
	t_line		*row;
	t_point		*pt;
	static int	column;

	row = malloc(sizeof(t_line));
	if (!row)
		return (NULL);
	points = ft_split(line, ' ');
	pt = NULL;
	x = 0;
	while (points[x] && points[x][0] != '\n')
	{
		join_point(&pt, create_point(x, y, ft_atoi(points[x])));
		x++;
	}
	ft_free_split(points);
	if (column != 0 && column != x)
	{
		printf("Find wrong length!!\n");
		free(row);
		ft_free_points(pt);
		return (NULL);
	}
	column = x;
	row->line = pt;
	row->next = NULL;
	return (row);
}

int	join_line(t_line **matrix, t_line *new_row)
{
	t_line	*last_row;

	if (new_row == NULL)
		return (-1);
	if (*matrix == NULL)
		*matrix = new_row;
	else
	{
		last_row = *matrix;
		while (last_row->next)
			last_row = last_row->next;
		last_row->next = new_row;
	}
	return (0);
}

void	prt_matrix(t_map *map)
{
	int		x;
	int		y;
	t_line	*row;
	t_point	*point;

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
	//		bresenham_line(point, point->next, img);
			printf("=============================\n");
			point = point->next;
			x++;
		}
		printf("===================\n");
		row = row->next;
		y++;
	}
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->matrix = NULL;
	map->column = 0;
	map->row = 0;
	return (map);
}

t_map	*parse_map(int fd)
{
	char	*line;
	int		y;
	t_map	*map;

	map = init_map();
	y = 0;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		if (*line != '\0' && join_line(&map->matrix, create_row(y, line)) == -1)
		{
			ft_free_map(map);
			free(line);
			get_next_line(fd, -1);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd, 0);
		y++;
	}
//	prt_matrix(map);
//	ft_free_map(map);
	return (map);
}
