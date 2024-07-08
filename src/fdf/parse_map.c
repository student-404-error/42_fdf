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
t_point	create_point(int x, int y, int z/*, char *line*/)
{
	t_point	point;

	point.x = cos(30 * PI / 180) * (x - y);
	point.y = sin(30 * PI / 180) * (x + y) - z;
	//point->color = get_color(line);
	point.argb[0] = 256;
	point.argb[1] = 256;
	point.argb[2] = 256;
	point.argb[3] = 256;
	return (point);
}

t_point	*first_row(t_point *row, int column, t_point p)
{
	t_point	*new_row;

	new_row = malloc(sizeof(t_point) * (column + 1));
	// while (i < column)
	// {
	// 	new_row[i] = row[i];
	// 	i++;
	// }
	ft_memcpy((void *) new_row, (void *) row, column);
	free(row);
	new_row[column] = p;
	return (new_row);
}

t_point	*create_row(int y, char *line)
{
	char		**row;
	static int	column;
	int			x;
	t_point		*points;

	row = ft_split(line, ' ');	// row is allocated. It must be freed.
	points = NULL;
	x = 0;
	while (row[x] && row[x][0] != '\n')
	{
		points = first_row(points, x,  create_point(x, y, ft_atoi(row[x])));
		printf("%f %f\n", points[x].x, points[x].y);
		x++;
	}
	if (column != 0 && column != x)
	{
		printf("error\n");
		exit(1);
	}
	column = x;
	ft_free_split(row);			// row is freed here.
	return (points);
}

void	parse_map(int fd)
{
	char	*line;
	int	row;
//	int	column;

	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		// matrix[row] = create_row(row, line);
		// row 만드는 것과 같은 방식으로 column도 만들면 됨.
		free(line);
		line = get_next_line(fd);
	//	if (column != (int)ft_strlen(line) && ft_strlen(line) != 0)
	//	{
	//		ft_printf("Found wrong line length. Exiting. %d\n", ft_strlen(line));
	//		exit(EXIT_FAILURE);
	//	}
		row++;
	}
	// create_points();
	// isometric_projection();
}
