/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:44:08 by jodone            #+#    #+#             */
/*   Updated: 2025/12/02 18:22:03 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_line(char *stash)
{
	char	*rest;
	int		start;
	int		i;

	start = 0;
	while (stash && stash[start] != '\n')
		start++;
	rest = malloc((ft_strlen(stash) - start + 1) * sizeof(char));
	i = 0;
	while (stash[start + 1])
	{
		rest[i] = stash[start + 1];
		i++;
		start++;
	}
	rest[i] = '\0';
	free(stash);
	return (rest);
}

char	*add_line(char *stash)
{
	char	*line;
	int		len_line;
	int		i;
	
	len_line = 0;
	while (stash && stash[len_line] != '\n')
		len_line++;
	line = malloc((len_line + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len_line)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	loop_breaker(char *stash)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (stash[i] == '\n' || stash[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

char	*buff_read(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;
	int		index;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	index = 1;
	if (!buffer)
		return (NULL);
	while (index > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break;
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		ft_strjoin(stash, buffer);
		index = loop_breaker(stash);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = NULL;
	stash = buff_read(fd, stash);
	line = add_line(stash);
	stash = rest_line(stash);
	if (stash && stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
