#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char *argv[])
{
	int	fd;
	if (argc < 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(fd));
	return EXIT_SUCCESS;
}
