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



void	cmd(t_pipex_b *pipex, char *av, char **envp)
{
	if (pipe(pipex->pipe_fd) == -1)
	{
		write_str("Broken pipe\n", 2);
		exit (32);
	}
	pipex->pid = fork();
	if (pipex->pid == -1)
	{
		write_str("Resource temporarily unavailable\n", 2);
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);
		exit (10);
	}
	if (!pipex->pid)
	{
		close(pipex->pipe_fd[0]);
		close(pipex->fd[0]);
		 if (dup2(pipex->pipe_fd[1], STDOUT_FILENO) == -1)
		{
			perror("dup2 stdout");
			close(pipex->pipe_fd[1]);
		close(pipex->fd[1]);

			exit(5);
		}
		close(pipex->fd[1]);
		close(pipex->pipe_fd[1]);
		execout(pipex, av, envp);
		exit(0);
	}
	else
	{
		close(pipex->pipe_fd[1]);
		if (dup2(pipex->pipe_fd[0], STDIN_FILENO) == -1)
		{
			perror("dup2 stdout");
			close(pipex->pipe_fd[0]);
			close(pipex->fd[0]);
			exit(5);
		}
		close(pipex->pipe_fd[0]);
		close(pipex->fd[0]);
		waitpid(pipex->pid, NULL, 0);
	}
}
