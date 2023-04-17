#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

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
	char		buffer[BUFFER_SIZE];
	char		*line;
	//static char	*reminder = NULL;
	int		i;
	
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	
	if (!line)
		return (NULL);
	
	i = 0;
	while (buffer[i] != '\n')
	{
		read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
	}
	

	return (line);
}
