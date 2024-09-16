/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:11:52 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/04 18:23:07 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/*char	*join(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		dest[j] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	static char	*dest;
	size_t		total_size;
	size_t		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_size = 0;
	i = 0;
	while (s1[i++] != '\0')
		total_size++;
	i = 0;
	while (s2[i++] != '\0')
		total_size++;
	dest = malloc((total_size) + 1);
	if (dest == NULL)
		return (NULL);
	dest = join(dest, s1, s2);
	return (dest);
}*/

void	update_b(char *buffer)
{
	size_t	i;
	size_t	len;
	size_t	length;
	char	*head;

	i = 0;
	length = 0;
	len = count_line(buffer);
	head = buffer;
	while (head[i++] != '\0')
		length++;
	ft_cpy(head, &buffer[len], length);
}

int	read_fd(char *buffer, int read_buffer, char **stash, int fd)
{
	size_t	i;

	i = 1;
	if (*stash && BUFFER_SIZE != read_buffer)
	{
		while (i)
		{
			i = 0;
			if ((int)count_line(*stash) >= read_buffer)
				break ;
			free(*stash);
			*stash = ft_strdup(buffer);
		}
	}
	read_buffer = read(fd, buffer, BUFFER_SIZE);
	return (read_buffer);
}

void	ft_cpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
