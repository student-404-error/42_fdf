/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:15:46 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/10 22:53:33 by seong-ki         ###   ########.fr       */
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
	if (!point)
		return (NULL);
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
		last_node->next = new_point;
	}
}

void	ft_free_points(t_point *pt)
{
    t_point *free_point;
    t_point *tmp_point;

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
	points = ft_split(line, ' ');	// row is allocated. It must be freed.
	pt = NULL;
	x = 0;
	while (points[x] && points[x][0] != '\n')
	{
		join_point(&pt, create_point(x, y, ft_atoi(points[x])));
		x++;
	}
	ft_free_split(points);			// row is freed here.
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
	int	i;
	int	j;
	t_line	*row;
	t_point	*point;
	
	row = map->matrix;
	i = 0;
	while (row)
	{
		j = 0;
		point = row->line;
		while (point)
		{
			printf("%d %d: %f %f\n", i, j, point->x, point->y);
			point = point->next;
			j++;
		}
		printf("===================\n");
		row = row->next;
		i++;
	}
}

void	ft_free_map(t_map *map)
{
	t_line	*free_row;
	t_line	*tmp_row;
	t_point	*free_point;
	t_point	*tmp_point;

	free_row = map->matrix;
	while (free_row)
	{
		tmp_row = free_row->next;
		free_point = free_row->line;
		while (free_point)
		{
			tmp_point = free_point->next;
			free(free_point);
			free_point = tmp_point;
		}
		free(free_row);
		free_row = tmp_row;
	}
	free(map);
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
	//	int	column;

	map = init_map();
	y = 0;
	while ((line = get_next_line(fd, 1)) != NULL)
	{
		ft_printf("%s", line);
		if (join_line(&map->matrix, create_row(y, line)) == -1)	// 한 줄이 반환이 되는거임.
		{
			ft_free_map(map);
			free(line);
			get_next_line(fd, -1);
			return (NULL);
		}
		free(line);
		y++;
	}
	prt_matrix(map);
	ft_free_map(map);
	return (NULL);
}
