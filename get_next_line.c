/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:34:48 by beroy             #+#    #+#             */
/*   Updated: 2023/11/25 14:46:58 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = "\0";
	char		*line;
	int			readed;

	readed = 1;
	if (read(fd, NULL, 0) < 0)
		return (ft_bzero(buff), NULL);
	line = ft_strdup(buff);
	if (line == NULL)
		return (NULL);
	while (readed && ft_linecheck(line) == 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed < 0)
			return (ft_bzero(buff), free(line), NULL);
		buff[readed] = 0;
		line = ft_strjoin(line, buff);
		if (line == NULL)
			return (NULL);
	}
	ft_buffclean(buff);
	if (line[0] == 0)
		return (free(line), NULL);
	return (line);
}
