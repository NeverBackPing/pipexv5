/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:13:54 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/11 16:13:54 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	manage_here_doc(t_pipex_b *pipex, char **av, int ac)
{
	pipex->index = 3;
	if (ac < 6)
	{
		ft_printf("./pipex HERE_DOC LIMITER cmd1 ... cmdn oufile\n");
		exit(0);
	}
	pipex->fd[1] = fd(pipex, av[ac - 1], 2);
	display_str(pipex, av);
	if (pipex->fd[1] == -1)
	{
		write_str2(av[ac - 1], ": Permission denied\n", 2);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		exit(13);
	}
}

void	manage_io(t_pipex_b *pipex, char **av, int ac)
{
	pipex->fd[0] = fd(pipex, av[1], 0);
	pipex->fd[1] = fd(pipex, av[ac - 1], 1);
	if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
	{
		write_str("Input/output error\n", 2);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		exit(5);
	}
	close(pipex->fd[0]);
	if (pipex->check == 1)
		pipex->index = ac - 2;
}

int	*malloc_pid(int ac)
{
	pid_t	*pids;

	pids = (pid_t *)malloc((ac - 2) * sizeof(pid_t));
	if (pids == NULL)
		exit(5);
	return (pids);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex_b	pipex;
	pid_t		*pids;
	size_t		i;

	i = 0;
	init_var(&pipex);
	if (ac < 5)
		return (ft_printf("./pipex infile cmd1...cmdn oufile\n"), 1);
	else if (ft_strcmp(av[1], "here_doc") == 0)
		manage_here_doc(&pipex, av, ac);
	else
		manage_io(&pipex, av, ac);
	pids = malloc_pid(ac);
	while (pipex.index < (size_t)ac - 2)
	{
		cmd(&pipex, av[pipex.index++], envp, pids);
		pids[i++] = pipex.pid;
	}
	last_dup(&pipex, pids);
	execout(&pipex, av[pipex.index], envp, pids);
	last_exec(&pipex, i - 1, pids);
	exit(pipex.out);
}
