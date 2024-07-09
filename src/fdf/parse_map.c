/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:15:46 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/07 16:06:48 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"

// void	create_matrix(char *line, int row, int column)
// {
//
// }
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
	point->x = cos(30 * PI / 180) * (x - y);
	point->y = sin(30 * PI / 180) * (x + y) - z;
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
		printf("%f %f\n", last_node->x, last_node->y);
		last_node->next = new_point;
	}
}

t_line	*create_row(int y, char *line)
{
	int			x;
	char		**points;
	t_point		*pt;
	static int	column;
	t_line		*row;

	row = malloc(sizeof(t_line));
	if (!row)
		return (NULL);
	points = ft_split(line, ' ');	// row is allocated. It must be freed.
	pt = NULL;
	x = 0;
	while (points[x] && points[x][0] != '\n')
	{
		join_point(&pt, create_point(x, y, ft_atoi(points[x])));
		x++;
	}
	if (column != 0 && column != x)
	{
		printf("error\n");
		exit(1);
	}
	column = x;
	ft_free_split(points);			// row is freed here.
	row->line = pt;
	row->next = NULL;
	return (row);
}
void	join_line(t_line **matrix, t_line *new_row)
{
	t_line	*last_row;

	if (*matrix == NULL)
		*matrix = new_row;
	else
	{
		last_row = *matrix;
		while (last_row->next)
			last_row = last_row->next;
		last_row->next = new_row;
	}
}
void	prt_matrix(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map->matrix)
	{
		j = 0;
		while (map->matrix->line)
		{
			printf("%d %d: %f %f |", i, j, map->matrix->line->x, map->matrix->line->y);
			map->matrix->line = map->matrix->line->next;
			j++;
		}
		printf("\n");
		map->matrix = map->matrix->next;
		i++;
	}
}

t_map	*parse_map(int fd)
{
	char	*line;
	int		y;
	t_map	*map;
	//	int	column;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		join_line(&map->matrix, create_row(y, line));	// 한 줄이 반환이 되는거임.
		free(line);
		line = get_next_line(fd);
		y++;
	}
	prt_matrix(map);
	// create_points();
	// isometric_projection();
	return (map);
}
