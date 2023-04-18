/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:48:34 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/04/18 19:28:03 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

char	*get_next_line(int fd);

int	main(void)
{
	int	fd;
	char	*line;
	
	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	
	printf("opened\n");
	
	line = get_next_line(fd);
	
	//printf("%s\n", line);
	
	free(line);

	close(fd);
	
	printf("closed\n");

	return (0);
}
