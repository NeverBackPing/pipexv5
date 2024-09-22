/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:13:41 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/11 16:13:41 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	access_path_bonus(t_pipex_b *pipex, char *cmd)
{
	if (access(pipex->path, F_OK) == 0)
	{
		if (access(pipex->path, X_OK) == 0)
			return (1);
		else
			return (write_str2(cmd, ": permission denied\n", 2), 1);
	}
	return (0);
}

void	fail_malloc(t_pipex_b *pipex, char *tmp_dir)
{
	free(tmp_dir);
	free(pipex->path);
	free(pipex->directory);
}

int	find_path(t_pipex_b *pipex, char *cmd, char **envp)
{
	char	*tmp_dir;

	envp_path(envp, pipex);
	pipex->directory = ft_strtok(pipex->path_head, ':');
	while (pipex->directory != NULL)
	{
		tmp_dir = ft_strjoin(pipex->directory, "/");
		if (tmp_dir == NULL)
			return (fail_malloc(pipex, tmp_dir), 1);
		pipex->path = ft_strjoin(tmp_dir, cmd);
		if (pipex->path == NULL)
			return (fail_malloc(pipex, tmp_dir), 1);
		if (access_path_bonus(pipex, cmd))
			return (free(pipex->directory), free(tmp_dir), 0);
		pipex->directory = ft_strtok(NULL, ':');
		free(pipex->path);
		free(tmp_dir);
	}
	if (ft_strchr(cmd, '/') != NULL)
		return (write_str2(cmd, ": No such file or directory\n", 2), 1);
	return (write_str2(cmd, ": Command not found\n", 2), 1);
}

void	exec_aout(t_pipex_b *pipex, char **envp, char *cmd)
{
	if (access(cmd, X_OK) == 0)
	{
		if (cmd[0] == '.' && cmd[1] == '/')
			NULL;
		else
		{
			error_cmd_aout(cmd);
			return ;
		}
	}
	pipex->flag = ft_split(cmd, ' ');
	if (pipex->flag == NULL)
		exit(5);
	if (execve(cmd, pipex->flag, envp) == -1)
	{
		if (ft_strchr(cmd, '/') != NULL)
		{
			write_str2(cmd, ": No such file or directory\n", 2);
			exit(2);
		}
		else
			write_str("Operation not permitted\n", 2);
		clean_split(pipex->flag);
		exit(1);
	}
}

void	execout(t_pipex_b *pipex, char *cmd, char **envp)
{
	char	**tmp_flag;

	if (access(cmd, F_OK) == 0)
	{
		exec_aout(pipex, envp, cmd);
		return ;
	}
	tmp_flag = ft_split(cmd, ' ');
	if (tmp_flag == NULL)
	{
		exit(5);
		return ;
	}
	if (find_path(pipex, tmp_flag[0], envp))
	{
		clean_split(tmp_flag);
		return ;
	}
	if (execve(pipex->path, tmp_flag, envp) == -1)
	{
		write_str("Operation not permitted\n", 2);
		clean_split(tmp_flag);
		close(pipex->fd[1]);
		exit(1);
	}
}
