#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 65535
# endif

int		get_next_line(int fd, char **line);

size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t destsize);
size_t	ft_strlcat(char *dest, char *src, size_t size);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *str1, char *str2);

#endif
