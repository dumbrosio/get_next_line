/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:29:05 by vd-ambro          #+#    #+#             */
/*   Updated: 2023/05/03 15:16:22 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_index(const char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	srcsize;
	size_t	i;
	char	*dst;

	i = 0;
	srcsize = ft_strlen(src);
	dst = malloc(sizeof(char) * (srcsize + 1));
	if (!dst)
		return (NULL);
	while (i < srcsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_strdup("");
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = 0;
	free(s1);
	return (joined);
}
