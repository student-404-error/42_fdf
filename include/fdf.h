/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:27:29 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/16 23:47:49 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define ESC_KEY 65307
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
	t_data	img_data;
}				t_vars;

typedef struct s_bresenham
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	p1_color;
	int	p2_color;
}	t_bresenham;

// fdf functions
t_map			*open_file(int ac, char **av);
void			draw_line(float scale, t_point p1, t_point p2, t_data *img);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_map			*parse_map(int fd);
void			ft_free_map(t_map *map);
unsigned int	color_inter(unsigned int c1, unsigned int c2, float t);
double			ft_percent(int start, int end, int current);
int				ft_gradient(int start, int end, double percent);
int				ft_pointsize(t_point *point);
int				ft_linesize(t_line *line);
t_point			*create_point(int x, int y, int z, char *line);
t_line			*create_row(int size, int y, char *line);
void			ft_free_points(t_point *pt);
void			join_point(t_point **row, t_point *new_point);
int				join_line(t_line **matrix, t_line *new_row);
unsigned int	get_color(char *line);
int				key_press(int keycode, t_vars *vars);
#endif // !FDF_H
