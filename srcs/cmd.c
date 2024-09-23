/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:14:52 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/11 16:14:52 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	path_envp(char **envp, t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->path_head = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->path_head = envp[i] + 5;
			break ;
		}
		i++;
	}
	return (0);
}

int	switch_cmd(t_pipex *pipex, char *av)
{
	pipex->cmd = ft_split((av), ' ');
	if (pipex->cmd == NULL)
		return (clean_split(pipex->tmp), 1);
	clean_split(pipex->tmp);
	return (0);
}

int	cmd_exec(t_pipex *pipex, char *av)
{
	pipex->check_aout = 0;
	if (access(pipex->tmp[0], F_OK) == 0)
	{
		if (access(pipex->tmp[0], X_OK) == 0)
		{
			pipex->check_aout = 1;
			if (switch_cmd(pipex, av))
				return (1);
			if (ft_strchr(pipex->cmd[0], '/') == NULL)
			{
				err_cmd(pipex, pipex->cmd[0]);
				return (clean_split(pipex->cmd), 1);
			}
			return (0);
		}
		else
		{
			pipex->exit_str = ft_strdup(DENIED);
			clean_split(pipex->tmp);
			return (1);
		}
	}
	if (switch_cmd(pipex, av))
		return (1);
	return (0);
}

int	access_path(t_pipex *pipex)
{
	if (access(pipex->path_find, F_OK) == 0)
	{
		if (access(pipex->path_find, X_OK) == 0)
			return (1);
		else
		{
			pipex->exit_str = ft_strdup(DENIED);
			return (1);
		}
	}
	return (0);
}

int	check_path(t_pipex *pipex, char *av, char **envp)
{
	if (check_space(av))
		return (err_cmd(pipex, av), 1);
	path_envp(envp, pipex);
	pipex->tmp = ft_split(av, ' ');
	if (pipex->tmp == NULL)
		return (1);
	if (cmd_exec(pipex, av))
		return (1);
	if (pipex->check_aout == 1)
		return (0);
	pipex->directory = ft_strtok(pipex->path_head, ':');
	while (pipex->directory != NULL)
	{
		pipex->tmp_dir = ft_strjoin(pipex->directory, "/");
		if (pipex->tmp_dir == NULL)
			return (free(pipex->directory), path_clean(pipex), 1);
		pipex->path_find = ft_strjoin(pipex->tmp_dir, pipex->cmd[0]);
		if (pipex->path_find == NULL)
			return (free(pipex->directory), path_clean(pipex), 1);
		if (access_path(pipex))
			return (free(pipex->directory), free(pipex->tmp_dir), 0);
		pipex->directory = ft_strtok(NULL, ':');
		path_clean(pipex);
	}
	return (err_cmd(pipex, pipex->cmd[0]), clean_split(pipex->cmd), 1);
}
