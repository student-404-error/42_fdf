/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:27:29 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/14 22:06:37 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define PI 3.1415926
# define SCALING 20
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_point {
	float			x;
	float			y;
	unsigned int	color;
	struct s_point	*next;
}	t_point;

typedef struct s_line {
	t_point			*line;
	struct s_line	*next;
}	t_line;

typedef struct s_map {
	t_line	*matrix;
	int		column;
	int		row;
}	t_map;

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
t_map	*open_file(int ac, char **av);
void	bresenham_line(t_point p1, t_point p2, t_data *img);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_map	*parse_map(int fd);
void	ft_free_map(t_map *map);
void	draw_line(t_point p1, t_point p2, t_data *img);
void	test_line(t_point p1, t_point p2, t_data *img);
#endif // !FDF_H
