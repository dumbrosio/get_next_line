/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:48:34 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/04/14 18:17:15 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	int		fd;
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	fd = open("test.txt", O_RDONLY);
	
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	
	printf("opened\n");
		read(fd, buf, BUFFER_SIZE);
	printf("%s\n", buf);
		close(fd);
	printf("closed");
	
	return 0;
}
