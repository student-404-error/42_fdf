#include "libft.h"
#include "fdf.h"
#include <stdio.h>

int open_file(int ac, char **av)
{
	int	fd;

	if (ac < 2)
	{
		ft_printf("Few arguments!!\n");
		return (EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR in open_file");
	}
	parse_map(fd);
	return (EXIT_SUCCESS);
}
