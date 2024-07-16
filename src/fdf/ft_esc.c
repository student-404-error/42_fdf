/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_esc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 23:46:27 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 23:48:17 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_window(t_vars *vars)
{
	if (vars->img_data.img != NULL)
		mlx_destroy_image(vars->mlx, vars->img_data.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		close_window(vars);
	return (0);
}
