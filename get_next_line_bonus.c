/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:55:54 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/04/30 13:26:28 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char *backup)
{
	size_t	size;
	size_t	i;
	char	*line;

	size = 0;
	if (*backup == '\0')
		return (NULL);
	while (backup[size] && backup[size] != '\n')
		size++;
	if (backup[size] == '\n')
		size++;
	line = malloc(sizeof(char) * size + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < size)
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_rest(char *backup)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (backup[i])
		str[j++] = backup[i++];
	str[j] = '\0';
	free(backup);
	return (str);
}

static char	*read_line(char *backup, int fd)
{
	int		byte;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	byte = 1;
	while (byte > 0 && get_index(backup, '\n') == -1)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == 0)
			break ;
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		backup = ft_strjoin(backup, buff);
	}
	free(buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*line;

	if (BUFFER_SIZE == 0 || fd < 0)
	{
		return (NULL);
	}
	backup[fd] = read_line(backup[fd], fd);
	if (!backup[fd])
		return (NULL);
	line = get_line(backup[fd]);
	backup[fd] = get_rest(backup[fd]);
	return (line);
}
