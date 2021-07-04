#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>

void	redirect_in(char *file);
void	redirect_out(char *file);

int		memory_free(char **mem);
void	double_memory_free(char **mem);
char	*find_path(char **env);
void	run_cmd(char *cmd, char **env);
#endif
