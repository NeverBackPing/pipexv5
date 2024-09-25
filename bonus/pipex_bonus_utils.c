/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:13:54 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/11 16:13:54 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

int	envp_path(char **envp, t_pipex_b *pipex)
{
	int	i;

	i = 0;
	pipex->path_head = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->path_head = envp[i] + 5;
			break ;
		}
		i++;
	}
	return (0);
}

void	init_var(t_pipex_b *pipex, char **envp)
{
	envp_path(envp, pipex);
	pipex->out = 0;
	pipex->index = 2;
	pipex->check = 0;
}


void	last_exec(t_pipex_b *pipex, size_t i, pid_t *pids)
{
	size_t		j;

	j = 0;
	if (pids)
	{
		while (j < i)
		{
			if (waitpid(pids[j], &pipex->status, 0) == -1)
				NULL;//perror("waitpid");
			pipex->out = WEXITSTATUS(pipex->status);
			j++;
		}
	}
}

void	last_dup(t_pipex_b *pipex)
{
	//1 swap with pipe_fd[1]
	if (dup2(pipex->fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2");
		close(pipex->fd[1]);
		exit(5);
	}
	close(pipex->fd[1]);
}
