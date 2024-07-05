/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:15:46 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/05 14:48:45 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	create_matrix(char *line, int row, int column)
// {
//
// }

void	create_row(char *line)
{
	char	**row;
	int		i;

	row = ft_split(line, ' ');	// row is allocated. It must be freed
	i = 0;
	while (row[i] && row[i][0] != '\n')
	{
		ft_printf("%d\n", ft_atoi(row[i]));
		i++;
	}
	ft_free_split(row);
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
		create_row(line);
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
