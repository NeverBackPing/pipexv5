/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_system.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:08:23 by sjossain          #+#    #+#             */
/*   Updated: 2024/08/14 15:28:01 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


void	exit_error(t_pipex *pipex, char **av)
{
	pipex->out = 0;
	pipex->out = WEXITSTATUS(pipex->status);
	perror_return(pipex, av[2]);
}

void	exit_error2(t_pipex *pipex, char **av)
{
	pipex->out = 0;
	pipex->out = WEXITSTATUS(pipex->status2);
	perror_return(pipex, av[3]);
	free_file(pipex);
}

void	system_err(t_pipex *pipex, const char *str)
{
	if (pipex->exit_str != NULL)
	{
		if (ft_strncmp(pipex->exit_str, str, ft_strlen(IO)) == 0)
			return ;
	}
	else
		write_str2(OFM, "\n", 2);
}
