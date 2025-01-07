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

void exit_here_doc(t_pipex_b *pipex, char *lim)
{
	if (ft_strncmp(pipex->line, lim, ft_strlen(lim)) == 0)
	{
		if (pipex->line[ft_strlen(lim) + 1] == '\0')
		{
			free(pipex->line);
			close(pipex->pipe_fd[1]);
			exit(0);
		}
	}
}

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
		close(pipex->pipe_fd[0]);
		pipex->line = get_next_line(STDOUT_FILENO);
		exit_here_doc(pipex, av[2]);
		if (write_pipe(pipex->pipe_fd[1], pipex->line) == -1)
		{
			if (pipex->line != NULL)
				free(pipex->line);
			close(pipex->pipe_fd[1]);
			return (write_str("write error\n", 2), 1);
		}
		free(pipex->line);
	}
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
	pipe_std(pipex);
	create(pipex);
	if (!pipex->pid)
	{
		close(pipex->pipe_fd[0]);
		read_infile(pipex, av);
	}
	check_here_doc(pipex);
	close(pipex->pipe_fd[1]);
	close(pipex->pipe_fd[0]);
	return (0);
}
