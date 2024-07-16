/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:15:46 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 23:07:24 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return (map);
}
