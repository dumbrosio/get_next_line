/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:55:54 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/05/06 12:18:42 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(char *reminder, int fd)
{
	int		byte;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	byte = 1;
	while (byte > 0 && get_index(reminder, '\n') == -1)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == 0)
			break ;
		if (byte == -1)
			return (free(reminder), NULL);
		buf[byte] = '\0';
		reminder = ft_strjoin(reminder, buf);
	}
	free(buf);
	return (reminder);
}

static char	*get_line(char *reminder)
{
	size_t	size;
	size_t	i;
	char	*line;

	size = 0;
	if (*reminder == '\0')
		return (NULL);
	while (reminder[size] && reminder[size] != '\n')
		size++;
	if (reminder[size] == '\n')
		size++;
	line = malloc(sizeof(char) * size + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < size)
	{
		line[i] = reminder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_rest(char *reminder)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (reminder[i] == '\n')
		i++;
	if (reminder[i] == '\0')
		return (free(reminder), NULL);
	str = malloc(sizeof(char) * (ft_strlen(reminder) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (reminder[i])
		str[j++] = reminder[i++];
	str[j] = '\0';
	free(reminder);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;

	if (fd < 0 || fd >= 4096 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	if (BUFFER_SIZE == 0)
	{
		exit(1);
		return (NULL);
	}
	reminder = read_line(reminder, fd);
	if (!reminder)
		return (NULL);
	line = get_line(reminder);
	reminder = get_rest(reminder);
	return (line);
}
