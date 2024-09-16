/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:25:40 by sjossain          #+#    #+#             */
/*   Updated: 2024/08/14 14:34:52 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_out(t_pipex *pipex)
{
	pipex->out = 0;
	if (pipex->exit_str != NULL && ft_strcmp(pipex->exit_str, OFM) != 0)
	{
		if (ft_strncmp(pipex->exit_str, OPD, ft_strlen(OPD)) == 0)
			pipex->out = 1;
		if (ft_strncmp(pipex->exit_str, PATH, ft_strlen(PATH)) == 0)
			pipex->out = 1;
		if (ft_strncmp(pipex->exit_str, NOSUCH, ft_strlen(NOSUCH)) == 0)
			pipex->out = 2;
		if (ft_strncmp(pipex->exit_str, IO, ft_strlen(IO)) == 0)
			pipex->out = 5;
		if (ft_strncmp(pipex->exit_str, DENIED, ft_strlen(DENIED)) == 0)
			pipex->out = 13;
		if (ft_strncmp(pipex->exit_str, CND, ft_strlen(CND)) == 0)
			pipex->out = 127;
	}
	else if (pipex->exit_str == NULL || ft_strcmp(pipex->exit_str, OFM) == 0)
		pipex->out = 12;
	if (pipex->exit_str != NULL)
			free(pipex->exit_str);
}
