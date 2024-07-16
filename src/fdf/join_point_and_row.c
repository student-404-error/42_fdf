/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_point_and_row.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:02:57 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 23:03:08 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
