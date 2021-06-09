/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:32:37 by hsamatha          #+#    #+#             */
/*   Updated: 2021/02/25 22:46:45 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (char *)&(s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (char *)&(s[i]);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*p;

	i = 0;
	len = 0;
	while (s1[i++])
		len = i;
	if (!(p = (char *)malloc((len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*dest;
	int		i;

	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = (char *)malloc(len * (sizeof(char)) + 1)))
		return (NULL);
	i = 0;
	while (*s1)
	{
		dest[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		dest[i] = *s2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		string;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	string = ft_strlen((char *)s);
	if (string < start)
		len = 0;
	else if ((string - start) < len)
		len = string - start;
	if (!(ptr = (char *)malloc(len * (sizeof(char)) + 1)))
		return (NULL);
	while (i < (int)len && s[i])
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
