/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:38 by donpark           #+#    #+#             */
/*   Updated: 2021/06/19 05:06:55 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"
# define READ 0
# define WRITE 1

void	clear_temp(void);
void	heredoc(char *limiter);
int		is_heredoc(char **argv);

void	create_fd(int ***fd, int pipe_cnt);
void	free_fd(int ***fd, int pipe_cnt);
void	create_pipe(int **fd, int cmd_cnt, int pipe_cnt);
void	connect_pipe(int **fd, int row, int io);
void	close_pipe(int **fd, int row);

void	redirect_in(char *file);
void	redirect_out(char *file, char **argv);

void	run_only_cmd1(char **argv, char **env);

void	run_cmd1(int **fd, int *i, char **argv, char **env);

void	child_heredoc_n(int **fd, int *i, char **argv, char **env);
void	child_n(int **fd, int *i, char **argv, char **env);
void	run_cmdn(int **fd, int *i, char **argv, char **env);

void	child_heredoc_mid(int **fd, int *i, char **argv, char **env);
void	child_mid(int **fd, int *i, char **argv, char **env);
void	run_cmd_mid(int **fd, int *i, char **argv, char **env);

int		memory_free(char **mem);
void	double_memory_free(char **mem);
char	**find_path_colonsplit(char **env);
void	cmd_execve(char *cmd, char **env);

int		ft_strcmp(char *s1, char *s2);
#endif
