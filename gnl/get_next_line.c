/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:11:33 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/04 18:25:32 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/*char	*ft_strdup(char *s)
{
	char	*ret;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	while (s[i++] != '\0')
		size++;
	ret = (char *)malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s, size + 1);
	return (ret);
}*/

size_t	count_line(char *stash)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (stash == NULL)
		return (0);
	if (stash[i] == '\n')
		return (1);
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		len++;
		i++;
	}
	if (stash[i] == '\n')
		len++;
	return (len);
}

char	*clear_s(char *stash)
{
	size_t	len;
	size_t	i;
	char	*line;

	i = 0;
	if (stash == NULL)
		return (NULL);
	len = count_line(stash);
	line = malloc((len + 1));
	if (line == NULL)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	is_end(char *buffer)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	if (buffer == NULL)
		return (1);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			result = 1;
			break ;
		}
		i++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	char			*stash;
	char			*line;
	int				read_b;

	stash = malloc(1);
	if (fd < 0 || BUFFER_SIZE <= 0 || !stash)
		return (buffer[0] = '\0', free(stash), NULL);
	read_b = 1;
	stash[0] = '\0';
	while (read_b > 0 && is_end(stash) == 0)
	{
		if (is_end(buffer) == 0)
		{
			read_b = read_fd(buffer, read_b, &stash, fd);
			if ((read_b <= 0 && !*buffer) || read_b < 0 || stash == NULL)
				return (buffer[0] = '\0', free(stash), NULL);
			buffer[read_b] = '\0';
		}
		line = ft_strdup(stash);
		free(stash);
		stash = ft_strjoin(line, buffer);
		free(line);
	}
	return (line = clear_s(stash), update_b(buffer), free(stash), line);
}
/*int main()
{
	int fd = open("test.txt", O_RDONLY);
	//int check = 0;
	printf("-------------------\n");
	char *line;
	while (1)
	{
		line = get_next_line(fd);

		if (line == NULL)
			break ;
		printf("%s", line);

		free(line);
	}
	printf("-------------------\n");
	if (line != NULL)
		free (line);
	return (0);
}*/