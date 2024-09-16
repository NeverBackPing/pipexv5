/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:48:41 by sjossain          #+#    #+#             */
/*   Updated: 2024/08/07 12:48:41 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	count_arg(char **str)
{
	size_t	len;
	int		i;
	int		j;

	i = 0;
	len = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
			j++;
		i++;
		len++;
	}
	return (len);
}

void	free_file(t_pipex *pipex)
{
	if (pipex->infile != NULL)
		free(pipex->infile);
	if (pipex->outfile != NULL)
		free(pipex->outfile);
}

char	*find_file(char *str)
{
	int		len;
	char	*file;

	len = ft_strlen(str);
	file = (char *)malloc((len + 1) * sizeof(char));
	if (file == NULL)
		return (NULL);
	ft_strlcpy(file, str, len + 1);
	return (file);
}

void	close_check(t_pipex  *pipex, char *filename)
{
	if (ft_strncmp(filename, pipex->infile, ft_strlen(pipex->infile)) == 0)
	{
		if (close(pipex->fd[0]) == 0)
			return ;
		else
		{
			error_close(pipex->infile);
			pipex->out = 5;
		}
		pipex->fd[0] = -1;
	}
	if (ft_strncmp(filename, pipex->outfile, ft_strlen(pipex->outfile)) == 0)
	{
		if (close(pipex->fd[1]) == 0)
			return ;
		else
		{
			error_close(pipex->infile);
			pipex->out = 5;
		}
		pipex->fd[1] = -1;
	}
}

int	close_fd(t_pipex *pipex)
{
if (access(pipex->infile, F_OK) == 0 && pipex->fd[0] > 0)
	{
		if (pipex->fd[0] > 0)
			close(pipex->fd[0]);
		else
			return (error_close(pipex->infile), 1);
		pipex->fd[0] = -1;
	}
	if (access(pipex->outfile, F_OK) == 0 && pipex->fd[1] > 0)
	{
		if (pipex->fd[1] > 0)
			close(pipex->fd[1]);
		else
			return (error_close(pipex->outfile), 1);
		pipex->fd[1] = -1;
	}
	if (pipex->out == 5)
		exit(pipex->out);
	return (0);
}
