/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:48:56 by beroy             #+#    #+#             */
/*   Updated: 2023/11/15 19:22:11 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t			len;
	char			buff[BUFF_SIZE];
	static char		*line;
	char			*str;
	static size_t	i = 0;

	len = 0;
	if (line[i] != '\n')
	{
		while (buff[len] != '\n' || buff[len] != 0)
		{
			read(fd, buff, BUFF_SIZE);
			line = ft_strljoin(line, buff, BUFF_SIZE);
			len = BUFF_SIZE;
		}
	}
	str = ft_strdup(buff, &i);
	return (str);
}

#include <fcntl.h>

int main(void)
{
	char	*str;
	int 	fd;

	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	printf("1 : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("2 : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("3 : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("4 : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("5 : %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("6 : %s\n", str);
	free(str);
	return (0);
}
