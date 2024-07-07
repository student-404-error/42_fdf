#include "fdf.h"
#include "libft.h"

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
