#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX sysconf(_SC_OPEN_MAX)	//65536
# endif

int		is_newline(char *backup);
int		split_line(char **backup, char **line, int cut_idx);
int		remains_data(char **backup, char **line, int read_size);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

size_t		ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
#endif
