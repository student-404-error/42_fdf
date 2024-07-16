/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:15:46 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 15:50:01 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int	hex_char_to_int(char c) {
	if ('0' <= c && c <= '9')
		return c - '0';
	else if ('a' <= c && c <= 'f')
		return c - 'a' + 10;
	else if ('A' <= c && c <= 'F')
		return c - 'A' + 10;
	return -1;
}

unsigned int	get_color(char *line)
{
	char			**color;
	char			*hex;
	unsigned int	result;
	int				value;

	color = ft_split(line, ',');
	if (color[1] == NULL)
		return (ft_free_split(color), 16777215);
	result = 0;
	hex = color[1] + 2;
	while (*hex && *hex != '\n')
	{
		value = hex_char_to_int(*hex++);
		result = (result << 4) | value;
	}
	ft_free_split(color);
	return (result);
}

t_point	*create_point(int x, int y, int z, char *line)
{
	t_point	*point;

	point = (t_point *) malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = ((0.866025 * (x - y)) * SCALING) + (WIDTH / 2);
	point->y = ((0.5 * (x + y) - z) * SCALING) + (HEIGHT / 4);
	point->color = get_color(line);
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

int	ft_pointsize(t_point *point)
{
	int		len;
	t_point	*ptr;

	len = 0;
	ptr = point;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	return (len);
}

int	ft_linesize(t_line *line)
{
	int		len;
	t_line	*ptr;

	len = 0;
	ptr = line;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	return (len);
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
		if (*line != '\0'\
		&& join_line(&map->matrix, create_row(map->row, y, line)) == -1)
		{
			ft_free_map(map);
			free(line);
			get_next_line(fd, -1);
			return (NULL);
		}
		free(line);
		map->row = ft_pointsize(map->matrix->line);
		line = get_next_line(fd, 0);
		y++;
	}
	map->column = ft_linesize(map->matrix);
	printf("%d %d\n", map->row, map->column);
	return (map);
}
