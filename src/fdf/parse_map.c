/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:15:46 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/28 17:20:31 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	create_matrix(char *line, int row, int column)
// {
//
// }

void	parse_map(int fd)
{
	char	*line;
	int	row;
	int	column;

	row = 0;
	line = get_next_line(fd);
	column = (int)ft_strlen(line);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
		if (column != (int)ft_strlen(line) && ft_strlen(line) != 0)
		{
			ft_printf("Found wrong line length. Exiting. %d\n", ft_strlen(line));
			exit(EXIT_FAILURE);
		}
		row++;
	}
	ft_printf("%d %d\n", row, column);
	// create_points();
	// isometric_projection();
}
