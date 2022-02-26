/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:48:47 by eozmert           #+#    #+#             */
/*   Updated: 2022/02/26 18:31:44 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd, char *next_linex)
{
    char *buffer;
    int next;
    int read_byte;

    read_byte = 1;
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    next = (int)ft_strchr(buffer, '\n');
    if (!buffer)
        return (0);
    while (next == 0 && read_byte != 0)
    {
        read_byte = read(fd, buffer, BUFFER_SIZE);
        next = (int)ft_strchr(buffer, '\n');
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

int ft_readline()
{
    return 0;
}

int ft_newline()
{
    return 0;
}

char *get_next_line(int fd)
{
    static char *next_line;
    char *buffer;
    
    if (fd < 0 || BUFFER_SIZE <=0 )
        return (0);
    next_line = ft_read(fd, next_line);
    next_line = ft_read(fd, next_line);
    printf("%s", next_line);
    return (NULL);
}