/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:27:29 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/06 20:51:59 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define PI 3.1415926
# define WIDTH 500
# define HEIGHT 500

typedef struct s_point {
	float	x;
	float	y;
	int		flag;
}				t_point;

typedef struct s_map {
	struct s_point	**matrix;
	int				column;
	int				row;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*win;
	void	*mlx;
}				t_vars;

// fdf functions
void	parse_map(int fd);
int		open_file(int ac, char **av);
void	parse_map(int fd);
#endif // !FDF_H
