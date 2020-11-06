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

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
int			newlinefound(char *s);
int			get_next_line(int fd, char **line);

#endif
