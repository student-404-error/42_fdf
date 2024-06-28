#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int	fd;
	if (argc < 2)
		return (1);
	(void) argv;
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return EXIT_SUCCESS;
}
