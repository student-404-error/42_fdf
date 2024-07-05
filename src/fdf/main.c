#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	bresenham_line(t_point p1, t_point p2, t_data *img)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs((int)p2.x - (int)p1.x);
	dy = abs((int)p2.y - (int)p1.y);
	sx = (p1.x < p2.x) ? 1 : -1;
	sy = (p1.y < p2.y) ? 1 : -1;
	err = dx - dy;

	while (1)
	{
		my_mlx_pixel_put(img, p1.x, p1.y, 0x0000FF00);
		if (p1.x == p2.x && p1.y == p2.y)
			break;
		e2 = err * 2;
		if (e2 > -dy) {
			err -= dy;
			p1.x += sx;
		}
		if (e2 < dx) {
			err += dx;
			p1.y += sy;
		}
	}
}

int	main(int argc, char *argv[])
{
	open_file(argc, argv);
	return (EXIT_SUCCESS);
}
/*
int main(int argc, char *argv[])
{
	t_point3D	p3d;
	t_point3D	p3d2;
	t_point2D	p2d;
	t_point2D	p2d2;
	t_data		img;
	t_vars		vars;
	(void) argc;
	(void) argv;
	p3d.x = 3;
	p3d.y = 5;
	p3d.z = 6;

	p3d2.x = 10;
	p3d2.y = 40;
	p3d2.z = 4;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	p2d.x = cos(30 * PI / 180) * (p3d.x - p3d.y) * 10;
	p2d.y = (sin(30 * PI / 180) * (p3d.x + p3d.y) - p3d.z) * 10;
	p2d2.x = cos(30 * PI / 180) * (p3d2.x - p3d2.y) * 10;
	p2d2.y = (sin(30 * PI / 180) * (p3d2.x + p3d2.y) - p3d2.z) * 10;
	if (p2d.x >= 0 && p2d.x < 500 && p2d.y >= 0 && p2d.y < 500 && 
	    p2d2.x >= 0 && p2d2.x < 500 && p2d2.y >= 0 && p2d2.y < 500) {
		bresenham_line(p2d, p2d2, &img);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_loop(vars.mlx);
	return EXIT_SUCCESS;
}

void	test()
{
	int	i = 0, j = 0;

	while (i < column)
	{
		while (j < row)
		{
			
			j++;
		}
		i++;
	}
}*/
