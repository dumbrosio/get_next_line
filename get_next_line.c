#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srclen && i < dstsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy((join + s1_len), s2, s2_len + 1);
	return (join);
}

char	*get_next_line(int fd)
{
	char		temp[BUFFER_SIZE + 1];
	char		*line;
	static char	*reminder = NULL;
	int		i;
	
	temp[BUFFER_SIZE] = '\0';	
	
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	
	if (reminder != NULL)
		strcpy(line, reminder);

	if (!line)
		return (NULL);


	while (!ft_strchr(temp, '\n'))
	{	
		read(fd, temp, BUFFER_SIZE);
		
		i = 0;
		while (temp[i] && temp[i] != '\n')
		{
			i++;
		}

		if (temp[i] == '\n')
		{
			line = strncat(line, temp, i + 1);
			reminder = (char *)malloc((sizeof(char) * BUFFER_SIZE) - i + 1);
			ft_strlcpy(reminder, temp + i + 1, BUFFER_SIZE - i +1);

			//printf("temp is %s\n", temp);
			//printf("line is %s\n", line);
			printf("reminder is %s\n", reminder);

		}
		else
			line = ft_strjoin(line, temp);


		//printf("temp_2 is %s\n", temp);
		printf("line is %s\n", line);
		
	}
	return (line);
}
