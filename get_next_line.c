/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanvandenbulck <jeanvandenbulck@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:24:54 by jvanden-          #+#    #+#             */
/*   Updated: 2020/11/09 10:38:06 by jeanvandenb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			read_next_line(int fd, char **linebuffer)
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

char		*cutafternewline(char *linebuffer)
{
	char	*newline;
	int		newlinemarker;

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

char		*getreadyfornextline(char *bufferline)
{
	int		newlinemarker;
	int		i;
	char	*newbufferline;

	i = 0;
	newlinemarker = 0;
	while (bufferline[newlinemarker] != '\n' && bufferline[newlinemarker])
		newlinemarker++;
	if (!(newbufferline = malloc(sizeof(char) *
	(ft_strlen(bufferline) - newlinemarker + 1))))
		return (0);
	if (bufferline[newlinemarker])
		newlinemarker++;
	while (bufferline[newlinemarker])
		newbufferline[i++] = bufferline[newlinemarker++];
	newbufferline[i] = '\0';
	free(bufferline);
	return (newbufferline);
}

int			get_next_line(int fd, char **line)
{
	static char	*linebuffer;
	int			returnvalue;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!linebuffer)
	{
		if (!(linebuffer = malloc(sizeof(char))))
			return (-1);
		linebuffer[0] = '\0';
	}
	returnvalue = read_next_line(fd, &linebuffer);
	if (!(*line = cutafternewline(linebuffer)))
		return (-1);
	if (returnvalue == 1)
		linebuffer = getreadyfornextline(linebuffer);
	else
	{
		free(linebuffer);
		linebuffer = 0;
	}
	return (returnvalue);
}
