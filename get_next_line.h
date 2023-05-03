/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:29:21 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/05/03 15:22:08 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		get_index(const char *s, char c);
char	*ft_strdup(const char *src);

#endif