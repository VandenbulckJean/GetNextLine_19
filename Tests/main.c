#include "get_next_line.h"

int main(int argc, char** argv)
{
	int fd;
	char *line;

	(void)argc;
	line = 0;
	fd = (open(argv[1], O_RDONLY));
	while (get_next_line(fd, &line) == 1)
		printf("%s\n", line);
	return (0);
}
