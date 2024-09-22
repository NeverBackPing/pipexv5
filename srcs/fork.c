/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 02:03:39 by sjossain          #+#    #+#             */
/*   Updated: 2024/08/15 02:03:59 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	manage_child(t_pipex *pipex, char *av, char **envp)
{
	if (access(pipex->infile, F_OK) == 0)
	{
		if (check_path(pipex, av, envp))
			return (exit_out(pipex), close_fd(pipex), 1);
	}
	if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
	{
		pipex->exit_str = ft_strdup(IO);
		return (system_err(pipex, IO), exit_out(pipex), 1);
	}
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
	{
		pipex->exit_str = ft_strdup(IO);
		return (system_err(pipex, IO), exit_out(pipex), 1);
	}
	close(pipex->pipe_fd[0]);
	if (pipex->check == 0)
	{
		if (exec_cmd(pipex, envp) == 1)
		{
			close_fd(pipex);
			return (exit_out(pipex), 1);
		}
	}
	return (0);
}

int	child_fork(t_pipex *pipex, char **av, char **envp)
{
	int	check_exit;

	check_exit = 0;
	if (pipex->child == -1)
		return (1);
	else if (pipex->child == 0)
	{
		if (manage_child(pipex, av[2], envp))
			check_exit = 1;
		if (pipex->check == 1)
			close_file(pipex);
		if (check_exit == 1 && pipex->check == 0)
			NULL;
		free_file(pipex);
	}
	if (check_exit == 1 && pipex->check == 0)
		return (1);
	return (0);
}

int	manage_child2(t_pipex *pipex, char *av, char **envp)
{
	if (check_path(pipex, av, envp))
	{
		return (exit_out(pipex), close_fd(pipex), 1);
	}
	if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
	{
		pipex->exit_str = ft_strdup(IO);
		system_err(pipex, IO);
		return (exit_out(pipex), 1);
	}
	if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
	{
		pipex->exit_str = ft_strdup(IO);
		system_err(pipex, IO);
		return (exit_out(pipex), 1);
	}
	close(pipex->pipe_fd[1]);
	if (exec_cmd(pipex, envp) == 1)
	{
		close_fd(pipex);
		exit_out(pipex);
		return (1);
	}
	return (0);
}

int	child2_fork(t_pipex *pipex, char **av, char **envp)
{
	int	check_exit;

	check_exit = 0;
	if (pipex->child2 == -1)
		return (1);
	else if (pipex->child2 == 0)
	{
		if (manage_child2(pipex, av[3], envp))
			check_exit = 1;
		free_file(pipex);
	}
	if (check_exit == 1)
		return (1);
	return (0);
}
