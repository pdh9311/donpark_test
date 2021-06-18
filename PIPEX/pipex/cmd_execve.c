/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:08:59 by donpark           #+#    #+#             */
/*   Updated: 2021/06/19 04:09:01 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		memory_free(char **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = 0;
		return (1);
	}
	return (0);
}

void	double_memory_free(char **mem)
{
	int		i;

	i = 0;
	while (mem[i])
	{
		free(mem[i]);
		mem[i] = 0;
		i++;
	}
	free(mem);
	mem = 0;
}
// 환경변수의 PATH를 찾는 함수
char	**find_path_colonsplit(char **env)
{
	int		i;
	char	**colon_split;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' &&
			env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
		{
			colon_split = ft_split(env[i] + 5, ':');
			return (colon_split);
		}
		i++;
	}
	return (NULL);
}
// cmd를 환경변수의 PATH에서 찾아서 실행하는 함수
void	cmd_execve(char *cmd, char **env)
{
	char	**colon_split;
	char	**cmd_split;
	char	*slash_join;
	char	*executed_location;
	int		i;

	colon_split = find_path_colonsplit(env);
	cmd_split = ft_split(cmd, ' ');
	i = 0;
	while (colon_split[i])
	{
		slash_join = ft_strjoin(colon_split[i], "/");
		executed_location = ft_strjoin(slash_join, cmd_split[0]);
		memory_free(&slash_join);
		execve(executed_location, (char *const *)cmd_split, NULL);
		memory_free(&executed_location);
		i++;
	}
	double_memory_free(colon_split);
	double_memory_free(cmd_split);
}
