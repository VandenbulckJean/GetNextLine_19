/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeanvandenbulck <jeanvandenbulck@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:26:14 by jvanden-          #+#    #+#             */
/*   Updated: 2020/11/09 10:38:12 by jeanvandenb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

int			ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
int			newlinefound(char *s);
int			get_next_line(int fd, char **line);

#endif
