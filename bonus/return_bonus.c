/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:14:00 by sjossain          #+#    #+#             */
/*   Updated: 2024/09/11 16:14:00 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	write_pipe(int outfile, char *str)
{
	if (write(outfile, str, ft_strlen(str)) == -1)
		return (-1);
	return (0);
}

void	write_str(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	write_str2(char *str, char *str2, int fd)
{
	write(fd, str, ft_strlen(str));
	write(fd, str2, ft_strlen(str2));
}

void	error_return(t_pipex_b *pipex, char *av)
{
	if (pipex->out == 1)
		write_str("Operation not permitted\n", STDERR_FILENO);
	if (pipex->out == 2)
		write_str2(av, " :No such file or directory\n", STDERR_FILENO);
	if (pipex->out == 5)
		write_str("Input/output error\n", STDERR_FILENO);
	if (pipex->out == 12)
		write_str("Out memory\n", STDERR_FILENO);
	if (pipex->out == 13)
		write_str2(av, " :Permission denied\n", STDERR_FILENO);
	if (pipex->out == 127)
		write_str2(av, " :command not found\n", STDERR_FILENO);
}