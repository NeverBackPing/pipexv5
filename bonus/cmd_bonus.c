/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:13:35 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/11 16:13:35 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	pid_error(t_pipex_b *pipex)
{
	write_str("Resource temporarily unavailable\n", 2);
	close(pipex->pipe_fd[0]);
	exit (10);
}

void	cmd_pid(t_pipex_b *pipex, char *av, char **envp)
{
	if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 stdout");
		close(pipex->pipe_fd[1]);
		close(pipex->fd[0]);
		exit(5);
	}
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	execout(pipex, av, envp);
	exit(0);
}

void	pipe_std(t_pipex_b *pipex)
{
	if (pipe(pipex->pipe_fd) == -1)
	{
		write_str("error pipe\n", 2);
		exit (32);
	}
}

void	create(t_pipex_b *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		pid_error(pipex);
}

void	cmd(t_pipex_b *pipex, char *av, char **envp)
{
	pipe_std(pipex);
	create(pipex);
	if (pipex->pid == 0)
		cmd_pid(pipex, av, envp);
	if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 stdout");
		close(pipex->pipe_fd[1]);
		close(pipex->fd[0]);
		exit(5);
	}
	close(pipex->pipe_fd[1]);
	close(pipex->pipe_fd[0]);
}
