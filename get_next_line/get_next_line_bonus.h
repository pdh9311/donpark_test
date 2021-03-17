#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 65535	// sysconf(_SC_OPEN_MAX)
# endif

int		is_newline(char *backup);
int		split_line(char **backup, char **line, int cut_idx, char *buf);
int		remains_data(char **backup, char **line, int read_size, char *buf);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
#endif
