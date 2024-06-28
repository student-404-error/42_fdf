#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <libft.h>

int main(int argc, char *argv[])
{
	int	fd;
	(void) argc;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Failed to read\n");
		return (1);
	}
	char	*line;
	line = get_next_line(fd);
	printf("line: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("line: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("line: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("line: %s", line);
	free(line);
	return EXIT_SUCCESS;
}
