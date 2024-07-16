/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:25:38 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 22:58:49 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
