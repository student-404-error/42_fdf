#include "libft.h"

int main(int argc, char *argv[])
{
	int	fd;

	if (argc < 2)
	{
		ft_printf("Few arguments!!\n");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Failed to read\n");
		return (EXIT_FAILURE);
	}
	parse_map(fd);
	return (EXIT_SUCCESS);
}
