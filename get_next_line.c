/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:43:32 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/04/22 23:21:49 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(int fd, char *reminder, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	buffer[bytes_read] = '\0';
	ft_strlcpy(reminder, buffer, BUFFER_SIZE + 1);
	return (bytes_read);
}

static char	*get_line(char *line, char *reminder, int *bytes_to_copy)
{
	char	*newline;

	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		*bytes_to_copy = newline - line;
		ft_strlcpy(reminder, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		*bytes_to_copy = ft_strlen(line);
		ft_strlcpy(reminder, "", BUFFER_SIZE + 1);
	}
	line[*bytes_to_copy] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	reminder[BUFFER_SIZE];
	char		buffer[BUFFER_SIZE];
	char		*line;
	int			bytes_read;
	int			bytes_to_copy;

	line = ft_strdup(reminder);
	while (!ft_strchr(line, '\n'))
	{
		bytes_read = read_buffer(fd, reminder, buffer);
		if (bytes_read <= 0)
			break ;
		line = ft_strjoinf(line, reminder);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	line = get_line(line, reminder, &bytes_to_copy);
	return (line);
}
