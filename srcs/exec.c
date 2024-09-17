/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:03:39 by sjossain          #+#    #+#             */
/*   Updated: 2024/08/15 02:03:59 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	exec_aout(t_pipex *pipex, char **envp)
{
	if (execve(pipex->cmd[0], pipex->cmd, envp) == -1)
	{
		if (pipex->check_aout == 1)
		{
			pipex->check_aout = 0;
			clean_split(pipex->cmd);
			free(pipex->path_find);
			return (0);
		}
		pipex->check_aout = 0;
		pipex->exit_str = ft_strdup(NOSUCH);
		clean_split(pipex->cmd);
		free(pipex->path_find);
		return (1);
	}
	return (0);
}

int	exec_cmd(t_pipex *pipex, char **envp)
{
	if (pipex->check_aout == 1)
	{
		if (exec_aout(pipex, envp) == 0)
			return (0);
		else
			return (1);
	}
	if (execve(pipex->path_find, pipex->cmd, envp) == -1)
	{
		print_error_cmd(pipex, pipex->cmd[0]);
		clean_split(pipex->cmd);
		free(pipex->path_find);
		return (1);
	}
	return (0);
}
