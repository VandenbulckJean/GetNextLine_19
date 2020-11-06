#include "get_next_line.h"

int	static		read_next_line(int fd, char **linebuffer)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	if (newlinefound(*linebuffer))
		return (1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		if (!(*linebuffer = ft_strjoin(*linebuffer, buffer)))
			return (-1);
		if (newlinefound(*linebuffer))
			return (1);
	}
	return (0);
}

char static		*cutafternewline(char *linebuffer)
{
	char *newline;
	int newlinemarker;

	newlinemarker = 0;
	while (linebuffer[newlinemarker] != '\n' && linebuffer[newlinemarker])
		newlinemarker++;
	if (!((newline) = malloc((sizeof(char) * (newlinemarker + 1)))))
		return (0);
	newline[newlinemarker] = '\0';
	while (newlinemarker--)
		newline[newlinemarker] = linebuffer[newlinemarker];
	return (newline);
}

char static		*getreadyfornextline(char *bufferline)
{
	int		newlinemarker;
	int		i;
	char	*newbufferline;

	i = 0;
	newlinemarker = 0;
	while (bufferline[newlinemarker] != '\n' && bufferline[newlinemarker])
		newlinemarker++;
	if (!(newbufferline = malloc(sizeof(char) * (ft_strlen(bufferline) - newlinemarker + 1))))
		return (0);
	if (bufferline[newlinemarker])
		newlinemarker++;
	while (bufferline[newlinemarker])
		newbufferline[i++] = bufferline[newlinemarker++];
	newbufferline[i] = '\0';
	free(bufferline);
	return (newbufferline);
}

int				get_next_line(int fd, char **line)
{
	static char	*fd_line_buffer[FOPEN_MAX];
	int			returnvalue;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!fd_line_buffer[fd])
	{
		if (!(*line = malloc(sizeof(char))))
			return (-1);
		*line[0] = '\0';
		fd_line_buffer[fd] = *line;
	}
	returnvalue = read_next_line(fd, &fd_line_buffer[fd]);
	if (!(*line = cutafternewline(fd_line_buffer[fd])))
		return (-1);
	if (returnvalue == 1)
		fd_line_buffer[fd] = getreadyfornextline(fd_line_buffer[fd]);
	else
	{
		free(fd_line_buffer[fd]);
		fd_line_buffer[fd] = 0;
		
	}
	return (returnvalue);
}
