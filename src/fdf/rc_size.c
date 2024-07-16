/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:59:44 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 23:03:43 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
