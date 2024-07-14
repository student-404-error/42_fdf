/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:19:07 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/14 16:46:09 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*open_file(int ac, char **av)
{
	int	fd;

	if (ac < 2)
	{
		ft_printf("Few arguments!!\n");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("ERROR in open_file");
	return (parse_map(fd));
}
