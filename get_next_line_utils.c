/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vd-ambro <vd-ambro@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:01:34 by vxvalerio         #+#    #+#             */
/*   Updated: 2023/04/20 18:21:33 by vd-ambro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char*	ft_strcpy(char* dest, const char* src)
{
	char* result = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return result;
}

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

char	*ft_strdup(const char *s1)
{
	char *s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*joined;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	free(s1);
	return (joined);
}