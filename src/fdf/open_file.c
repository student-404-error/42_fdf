/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:19:07 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/17 14:40:32 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_map	*open_file(int ac, char **av)
{
	int		fd;
	t_map	*map;

	if (ac < 2)
	{
		ft_printf("Few arguments!!\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("ERROR in open_file");
	map = parse_map(fd);
	if (!map)
		return (close(fd), ft_error("Data not found."), NULL);
	close(fd);
	return (map);
}
