#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		is_newline(char *s);
int		split_line(char **backup, char **line, int cut_idx, char *buf);
int		remains_data(char **backup, char **line, int read_size, char *buf);
int		get_next_line(char **line);
#endif
