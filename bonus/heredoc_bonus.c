/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:13:50 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/11 16:13:50 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	read_infile(t_pipex_b *pipex, char **av)
{
	if (av[2][0] == '\0')
	{
		write_pipe(pipex->pipe_fd[1], "\n");
		exit(0);
	}
	while (1)
	{
		write(1, "pipe heredoc> ", ft_strlen("pipe heredoc> "));
		pipex->line = get_next_line(STDOUT_FILENO);
		if (ft_strncmp(pipex->line, av[2], ft_strlen(av[2])) == 0)
		{
			free(pipex->line);
			exit(0);
		}
		if (write_pipe(pipex->pipe_fd[1], pipex->line) == -1)
		{
			if (pipex->line != NULL)
				free(pipex->line);
			return (write_str("write error\n", 2), 1);
		}
		free(pipex->line);
	}
	if (pipex->line != NULL)
		free(pipex->line);
	return (0);
}

void	check_here_doc(t_pipex_b *pipex)
{
	if (close(pipex->pipe_fd[1]) == -1)
	{
		write_str("close error\n", 2);
		exit(5);
	}
	if (dup2(pipex->pipe_fd[0], 0))
	{
		write_str("Input/output error\n", 2);
		exit(5);
	}
	wait(NULL);
}

int	display_str(t_pipex_b *pipex, char **av)
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
		exit (10);
	}
	if (!pipex->pid)
	{
		close(pipex->pipe_fd[0]);
		read_infile(pipex, av);
	}
	else
		check_here_doc(pipex);
	return (0);
}
