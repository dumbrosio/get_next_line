/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:43:32 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/04/20 18:27:49 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char reminder[BUFFER_SIZE + 1];
	char *line;
	char *newline;
	int bytes_read;
	int bytes_to_copy;

	printf("first reminder: %s\n", reminder);

	line = ft_strdup(reminder);
	while (!(ft_strchr(line, '\n')) && (bytes_read = read(fd, reminder, BUFFER_SIZE)) > 0)
	{
		reminder[bytes_read] = '\0';
		// printf("bytes read: %d\n", bytes_read);
		line = ft_strjoin(line, reminder);
	}

	if (ft_strlen(line) == 0)
		return NULL;

	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		bytes_to_copy = newline - line;
		ft_strlcpy(reminder, newline + 1, BUFFER_SIZE + 1);
		printf("reminder: %s\n", reminder);
	}
	else
	{
		printf("newline is %s\n", newline);
		bytes_to_copy = ft_strlen(line);
		ft_strlcpy(reminder, "", BUFFER_SIZE + 1);
	}

	line[bytes_to_copy] = '\0';
	return line;
}