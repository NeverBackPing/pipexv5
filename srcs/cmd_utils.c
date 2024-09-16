/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:14:52 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/11 16:14:52 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	path_clean(t_pipex *pipex)
{
	if (pipex->path_find != NULL)
		free(pipex->path_find);
	if (pipex->tmp_dir != NULL)
		free(pipex->tmp_dir);
}

void	clean_split(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	if (array)
	{
		while (array[i] != NULL)
			free(array[i++]);
		free(array);
	}
}

void	print_error(t_pipex *pipex)
{
	if (ft_strchr(pipex->cmd[0], '/') != NULL)
	{
		pipex->exit_str = ft_strdup(NOSUCH);
	}
	else if (ft_strchr(pipex->cmd[0], '~') != NULL)
	{
		pipex->exit_str = ft_strdup(NOSUCH);
	}
	else
		pipex->exit_str = ft_strdup(CND);

}
