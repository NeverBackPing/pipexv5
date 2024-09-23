/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:14:22 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/11 16:14:22 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_one(t_pipex *pipex, char **av, char **envp)
{
	if (pipex->child < 0)
	{
		write_str("Resource temporarily unavailable", 2);
		exit (10);
	}
	if (pipex->child == 0)
	{
		pipex->out = 0;
		if (child_fork(pipex, av, envp))
		{
			exit(pipex->out);
		}
		else
		{
			exit(pipex->out);
		}
	}
}

void	child_second(t_pipex *pipex, char **av, char **envp)
{
	if (pipex->child2 < 0)
	{
		write_str("Resource temporarily unavailable", 2);
		exit (10);
	}
	if (pipex->child2 == 0)
	{
		pipex->out = 0;
		if (child2_fork(pipex, av, envp))
		{
			exit(pipex->out);
		}
		else
		{
			exit(pipex->out);
		}
	}
}

int	fork_main(t_pipex *pipex, char **av, char **envp)
{
	pipex->child = fork();
	child_one(pipex, av, envp);
	pipex->child2 = fork();
	child_second(pipex, av, envp);
	return (0);
}

void	init_var(t_pipex *pipex)
{
	pipex->status = 0;
	pipex->status2 = 0;
	pipex->out = 0;
	pipex->exit_str = NULL;
	pipex->path_find = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	init_var(&pipex);
	if (ac == 5)
	{
		if (pipe(pipex.pipe_fd) < 0)
		{
			write_str("Broken pipe", 2);
			exit (32);
		}
		file_descriptor(&pipex, av);
		fork_main(&pipex, av, envp);
		close_file(&pipex);
		waitpid(pipex.child, &pipex.status, 0);
		if (WIFEXITED(pipex.status))
			exit_error(&pipex, av);
		waitpid(pipex.child2, &pipex.status2, 0);
		if (WIFEXITED(pipex.status2))
			exit_error2(&pipex, av);
	}
	else
		ft_printf("./pipex infile cmd1 cmd2 oufile\n");
	exit (pipex.out);
}
