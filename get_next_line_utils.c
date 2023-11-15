/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:00 by beroy             #+#    #+#             */
/*   Updated: 2023/11/15 19:20:46 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlennl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup(char *src, size_t *i)
{
	char	*dup;
	size_t	j;

	j = 0;
	dup = malloc(sizeof(char) * (ft_strlennl(src + *i) + 1));
	if (dup == NULL)
		return (dup);
	while (src[*i] && src[*i] != '\n')
	{
		dup[j] = src[*i];
		j++;
		*i += 1;
	}
	dup[j] = 0;
	if (src[*i] == '\n')
		*i += 1;
	return (dup);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strljoin(char *s1, char *s2, size_t l)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + l + 1));
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (i + j < l)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	free (s1);
	return (str);
}