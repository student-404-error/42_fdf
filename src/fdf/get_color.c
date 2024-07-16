/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:00:43 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 23:06:55 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hex_char_to_int(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if ('a' <= c && c <= 'f')
		return (c - 'a' + 10);
	else if ('A' <= c && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

unsigned int	get_color(char *line)
{
	char			**color;
	char			*hex;
	unsigned int	result;
	int				value;

	color = ft_split(line, ',');
	if (color[1] == NULL)
		return (ft_free_split(color), 16777215);
	result = 0;
	hex = color[1] + 2;
	while (*hex && *hex != '\n')
	{
		value = hex_char_to_int(*hex++);
		result = (result << 4) | value;
	}
	ft_free_split(color);
	return (result);
}
