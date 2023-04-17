#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

char	*get_next_line(int fd)
{
	char		*buf;
	//static char	*tmp = NULL;
	//char		*src;
	//char		*dst;
	//ssize_t		n;
	
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);

	return (buf);
}
