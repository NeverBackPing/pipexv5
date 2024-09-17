/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:48:38 by sjossain          #+#    #+#             */
/*   Updated: 2024/08/07 12:48:38 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_file(t_pipex *pipex)
{
	if (close_fd(pipex))
	{
		exit_out(pipex);
		exit(pipex->out);
	}
	close(pipex->pipe_fd[1]);
}

int	fd_outfile(t_pipex *pipex)
{
	if (pipex->fd[1] == -1)
	{
		pipex->fd[1] = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (access(pipex->outfile, F_OK) == 0)
		{
			if (access(pipex->outfile, W_OK) == 0)
			{
				return (0);
			}
			else
			{
				error_file_denied(pipex->outfile, pipex);
				return (1);
			}
		}
		else
			return (error_file(pipex->outfile), 1);
	}
	return (0);
}


int	fd_infile(t_pipex *pipex)
{
	if (pipex->fd[0] == -1)
	{
		if (access(pipex->infile, F_OK) == 0)
		{
			if (access(pipex->infile, R_OK) != 0)
				return (error_file_denied(pipex->infile, pipex), 0);
		}
		error_file(pipex->infile);
	}
	return (0);
}

int	check_fd(t_pipex *pipex, char **str)
{
	pipex->check = 0;
	pipex->infile = find_file(str[1]);
	pipex->outfile = find_file(str[count_arg(str) - 1]);
	if (pipex->infile == NULL || pipex->outfile == NULL)
		return (1);
	pipex->fd[0] = open(pipex->infile, O_RDONLY, 0777);
	if (fd_infile(pipex))
		return (1);
	pipex->fd[1] = open(pipex->outfile, O_WRONLY | O_TRUNC, 0777);
	if (fd_outfile(pipex))
		return (1);
	if (access(pipex->infile, R_OK) != 0 && pipex->fd[0]  > 0)
		return (error_file_denied(pipex->infile, pipex), 1);
	if (access(pipex->infile, F_OK) != 0)
	{
		pipex->fd[0] = open("/dev/null", O_RDONLY, 0777);
		if (pipex->fd[0]  < 0)
			return (error_file_denied("/dev/null", pipex), 1);
		pipex->check = 1;
	}
	if (access(pipex->outfile, W_OK) != 0 || pipex->fd[0] <= 0)
		return (error_file_denied(pipex->outfile, pipex), 1);
	return (0);
}

void	file_descriptor(t_pipex *pipex, char **av)
{
	pipex->fd[0] = 0;
	pipex->fd[1] = 0;
	if (check_fd(pipex, av))
	{
		close_fd(pipex);
		if (pipex->infile != NULL)
			free(pipex->infile);
		if (pipex->outfile != NULL)
			free(pipex->outfile);
		exit_out(pipex);
		exit(pipex->out);
	}
}
