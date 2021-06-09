/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:54:36 by hsamatha          #+#    #+#             */
/*   Updated: 2021/06/09 13:27:10 by hsamatha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_final(char **cache, char **line)
{
	if (!(*line = ft_strdup(*cache))) //duplicate the rest
		return (-1);
	free(*cache);  //and free
	*cache = NULL;
	return (0);
}

int		ft_newline(char **cache, char *ptr_n, char **line)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*cache) - ft_strlen(ptr_n); //len = from 0 to \n // ft_strlen(ptr_n) = from \n till \0
	if (!(*line = ft_substr(*cache, 0, len))) //copy to line chars before \n
		return (-1);
	if (!(tmp = ft_substr(*cache, ft_strlen(*line) + 1, ft_strlen(ptr_n)))) //copy starting from the previous end of line the length of prt
		return (-1);
	free(*cache);
	*cache = NULL;
	*cache = tmp; //new cache
	return (1);
}

int		ft_line(char **cache, char *ptr_n, char **line, char *buff)
{
	free(buff);
	return (ft_newline(cache, ptr_n, line));
}

void	ft_join(char **cache, char *buff, char *tmp)
{
	tmp = ft_strjoin(*cache, buff); 
	free(*cache);
	*cache = tmp; //new cache + buff
}

int		get_next_line(int fd, char **line)
{
	static char *cache;
	char		*buff;
	int			byte_was_read;
	char		*ptr_n;
	char		*tmp;

	if (!line || !(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))
		|| fd < 0 || BUFFER_SIZE < 1 || (read(fd, NULL, 0) == -1)) //all invalid cases
		return (-1);
	tmp = NULL;
	if (!cache)
		cache = ft_strdup(""); //in first entry - empty
	if ((ptr_n = ft_strchr(cache, '\n'))) //valid for the 2nd entry
		return (ft_line(&cache, ptr_n, line, buff));
	while ((byte_was_read = read(fd, buff, BUFFER_SIZE)) > 0) //read into buff, count how many has read
	{
		buff[byte_was_read] = '\0'; //to be able to perform the following operations
		ft_join(&cache, buff, tmp); //give new cache, new buff and empte tmp
		if ((ptr_n = ft_strchr(cache, '\n'))) //valif for all entries 
			return (ft_line(&cache, ptr_n, line, buff));
	}
	free(buff);
	if ((ptr_n = ft_strchr(cache, '\0'))) //when nothing to read :'(
		return (ft_final(&cache, line));
	return ((byte_was_read == -1) ? -1 : 0);
}
