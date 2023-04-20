/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:48:34 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/04/20 18:30:29 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

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
	
	// line = get_next_line(fd);
	
	// // printf("returned line is: %s\n", line);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line: %s\n", line);
		free(line);
	}
	
	// free(line);	

	close(fd);
	
	printf("closed\n");

	return (0);
}
