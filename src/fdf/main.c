#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*win;
	void	*mlx;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	press_esc_key(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_data	img;
	t_vars	vars;
	int	img_height = 500;
	int	img_width = 500;
	int	color;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 500, 500);// 이미지 instance 생성
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//이미지의 주소 할당
	for (int i = 0; i < img_height - 1; ++i)
	{
		for (int j = 0; j < img_width - 1; ++j)
		{
			double b = (double)(img_width - j) / (img_width - 1);
			double g = (double)(i) / (img_height - 1);
			double r = 1;
			color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) + ((int)(255.999 * b));
			my_mlx_pixel_put(&img, i, j, color);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);//이미지를 윈도우에 올린다.
	mlx_key_hook(vars.win, press_esc_key, &vars);
	mlx_loop(vars.mlx);
}
