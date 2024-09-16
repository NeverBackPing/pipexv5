/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:54:26 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/04 18:18:18 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "../includes/pipex.h"

//char	*ft_strjoin(char *s1, char *s2);
void	ft_cpy(char *dest, const char *src, size_t size);
char	*get_next_line(int fd);
int		is_end(char *buffer);
//char	*join(char *dest, char *s1, char *s2);
char	*clear_s(char *stash);
//char	*ft_strdup(char *s);
void	update_b(char *buffer);
int		read_fd(char *buffer, int read_buffer, char **stash, int fd);
size_t	count_line(char *stash);
#endif
