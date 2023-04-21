/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:43:32 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/04/21 18:03:35 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	reminder[BUFFER_SIZE + 1];
	char	*line;
	char	*newline;
	int	bytes_read;
	int	bytes_to_copy;

	line = ft_strdup(reminder);
	while (!(ft_strchr(line, '\n'))
		&& (bytes_read = read(fd, reminder, BUFFER_SIZE)) > 0)
	{
		reminder[bytes_read] = '\0';
		line = ft_strjoin(line, reminder);
	}
	if (ft_strlen(line) == 0)
		return (NULL);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		bytes_to_copy = newline - line;
		ft_strlcpy(reminder, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		bytes_to_copy = ft_strlen(line);
		ft_strlcpy(reminder, "", BUFFER_SIZE + 1);
	}
	line[bytes_to_copy] = '\0';
	return (line);
}
