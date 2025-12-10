/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:44:22 by jodone            #+#    #+#             */
/*   Updated: 2025/12/10 16:08:26 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*rest_line(char *stash)
{
	char	*result;
	int		len;
	int		i;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	result = calloc(ft_strlen(stash) - len + 1, sizeof(char));
	i = 0;
	len++;
	while (stash[len])
		result[i++] = stash[len++];
	result[i] = '\0';
	free(stash);
	return (result);
}

char	*add_line(char *stash)
{
	char	*result;
	int		len;
	int		i;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	result = calloc(len + 2, sizeof(char));
	i = 0;
	while (i <= len)
	{
		result[i] = stash[i];
		i++;
	}
	return (result);
}

int	loop_breaker(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (-1);
		i++;
	}
	return (1);
}

char	*read_buffer(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;
	int		index;

	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	index = 1;
	while (index > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		index = loop_breaker(stash);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_buffer(fd, stash);
	line = add_line(stash);
	stash = rest_line(stash);
	if (stash && stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char	*line;
	int		fd;
	int		i;

	fd = open("test", O_RDONLY);
	i = 5;
	while (i > 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i--;
	}
	close (fd);
}