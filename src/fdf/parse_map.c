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

	point = malloc(sizeof(t_point));
	point->x = cos(30 * PI / 180) * (x - y);
	point->y = sin(30 * PI / 180) * (x + y) - z;
	//point->color = get_color(line);
	point->argb[0] = 256;
	point->argb[1] = 256;
	point->argb[2] = 256;
	point->argb[3] = 256;
	return (point);
}

void	create_row(int line_num, char *line)
{
	char		**row;
	static int	column;
	int			i;
	t_point		*p;

	row = ft_split(line, ' ');	// row is allocated. It must be freed.
	i = 0;
	while (row[i] && row[i][0] != '\n')
	{
		p = create_point(i, line_num, ft_atoi(row[i]));
		printf("%f %f\n", p->x, p->y);
		free(p);
		i++;
	}
	printf("column: %d\n", i);
	if (column != 0 && column != i)
	{
		printf("error\n");
		exit(1);
	}
	column = i;
	ft_free_split(row);			// row is freed here.
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
		create_row(row, line);
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
