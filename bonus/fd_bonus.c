/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:13:47 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/11 16:13:47 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	fd(t_pipex_b *pipex, char *filename, int check_fd)
{
	if (check_fd == 0)
	{
		pipex->code = open(filename, O_RDONLY, 0777);
		if (pipex->code == -1)
		{
			pipex->code = open("/dev/null", O_RDONLY, 0777);
			pipex->check = 1;
		}
	}
	if (check_fd == 1)
	{
		pipex->code = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (pipex->code == -1)
		{
			write_str2(filename, ": Permission denied\n", 2);
			close(pipex->fd[0]);
			exit(13);
		}
	}
	if (check_fd == 2)
		pipex->code = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	return (pipex->code);
}
