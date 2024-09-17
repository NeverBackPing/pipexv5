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

int	nb_slash(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == '/')
	{
		len++;
		i++;
		if (str[i] != '/')
			len -= 1;
	}
	return (len);
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

void	print_error_cmd(t_pipex *pipex, char *s)
{
	if (ft_strchr(s, '/') != NULL)
		pipex->exit_str = ft_strdup(NOSUCH);
	else
		pipex->exit_str = ft_strdup(CND);

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
