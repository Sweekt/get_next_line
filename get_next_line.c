/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:48:56 by beroy             #+#    #+#             */
/*   Updated: 2023/11/16 17:34:06 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_check_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_lineclean(char *str)
{
	char	*newline;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	newline = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (newline == NULL)
		return (newline);
	while (str[i + j])
	{
		newline[j] = str[i + j];
		j++;
	}
	newline[j] = 0;
	free(str);
	return (newline);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	char			*str;
	static char		*line = 0;
	ssize_t			readed;

	readed = 1;
	if (read(fd, NULL, 0) < 0)
		return (NULL);
	while (ft_check_nl(line) == 0 && readed)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed <= 0)
			return (NULL);
		buff[readed] = 0;
		line = ft_strjoin(line, buff);
		if (line == NULL)
			return (NULL);
	}
	str = ft_strdup(line);
	if (str == NULL)
		return (NULL);
	line = ft_lineclean(line);
	if (line == NULL)
		return (NULL);
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