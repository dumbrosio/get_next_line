/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:47:05 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/05/16 00:40:22 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_line(char *line)
{
	int		i;
	char	*newstr;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	newstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!newstr)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		newstr[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		newstr[i] = line[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*get_rest(char *str)
{
	char	*newstr;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!newstr)
		return (NULL);
	i++;
	temp = str + i;
	j = 0;
	while (*temp)
		newstr[j++] = *temp++;
	newstr[j] = '\0';
	free(str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reminder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reminder = ft_read(fd, reminder);
	if (!reminder)
		return (NULL);
	line = get_line(reminder);
	reminder = get_rest(reminder);
	return (line);
}
