/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:58:06 by eozmert           #+#    #+#             */
/*   Updated: 2022/02/28 13:41:59 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *next_linex)
{
	char	*buffer;
	int		read_byte;

	read_byte = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (!ft_strchr(next_linex, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		next_linex = ft_strjoin(next_linex, buffer);
	}
	free(buffer);
	return (next_linex);
}

char	*ft_readline(char *next_linex)
{
	char	*read_line;

	if (!next_linex[0])
		return (NULL);
	read_line = ft_substr(next_linex, 0,
			(ft_strchr(next_linex, '\n') - next_linex + 1));
	if (!read_line)
		return (NULL);
	return (read_line);
}

char	*ft_newline(char *next_linex)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (next_linex[i] && next_linex[i] != '\n')
		i++;
	if (!next_linex[i])
	{
		free(next_linex);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(next_linex) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (next_linex[i])
		str[j++] = next_linex[i++];
	str[j] = '\0';
	free(next_linex);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*next_line[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line[fd] = ft_read(fd, next_line[fd]);
	if (!next_line[fd])
		return (NULL);
	line = ft_readline(next_line[fd]);
	next_line[fd] = ft_newline(next_line[fd]);
	return (line);
}
