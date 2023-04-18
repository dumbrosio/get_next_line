/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:48:34 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/04/19 01:42:43 by vd-ambro         ###   ########.fr       */
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
	
	printf("returned line is: %s\n", line);
	
	free(line);

	close(fd);
	
	printf("closed\n");

	return (0);
}
