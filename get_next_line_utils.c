/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanvandenbulck <jeanvandenbulck@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:05:41 by jeanvandenb       #+#    #+#             */
/*   Updated: 2020/11/06 12:48:18 by jeanvandenb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char *newline;
	char *temp;
	int i;

	i = 0;
	if (!(newline = (char*)malloc(sizeof(char) *
	(ft_strlen(line) + ft_strlen(buffer) + 1))))
		return (NULL);
	temp = newline;
	while (line[i])
		*temp++ = line[i++];
	while (*buffer)
		*temp++ = *buffer++;
	*temp = '\0';
	free(line);
	return (newline);
}

int		newlinefound(char *linebuffer)
{
	int		i;

	i = 0;
	while (linebuffer[i])
	{
		if (linebuffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
