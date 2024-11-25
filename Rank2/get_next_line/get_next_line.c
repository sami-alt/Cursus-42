/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 10:37:04 by sraiha            #+#    #+#             */
/*   Updated: 2024-11-20 10:37:04 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *clear_buffer(char *curr_buffer, char *temp_buffer)
{
    char *temp;

    temp = ft_strjoin(curr_buffer, temp_buffer);
    free(curr_buffer);
    return (temp);
}

char    *get_line(char *buffer)
{
    char *line;
    size_t line_len;

    line_len = 0;
    if (!buffer[line_len])
        return (NULL);
    while (buffer[line_len] && buffer[line_len] != '\n')
        line_len++;
    line = ft_calloc((line_len + 2), sizeof(char));
    if (!line)
        return (NULL);
    line_len = 0;
    while (buffer[line_len] && buffer[line_len] != '\n')
    {   
        line[line_len] = buffer[line_len];
        line_len++;
    }
    if (buffer[line_len] && buffer[line_len] == '\n')
        line[line_len++] = '\n';
    //printf("get line func: %s", line);
    return (line);
}

char    *buffer_to_next_line(char *curr_buffer)
{
    char *new_buffer;
    size_t i;
    size_t j;

    i = 0;
    while (curr_buffer[i] && curr_buffer[i] != '\n')
        i++; 
    if (!curr_buffer[i])
    {
        free(curr_buffer);
        return (NULL);
    }
    new_buffer = ft_calloc((ft_strlen(curr_buffer) - i + 1), sizeof(char));
    i++;
    j = 0;
    while (curr_buffer[i])
        new_buffer[j++] = curr_buffer[i++];
    free(curr_buffer);
    return (new_buffer);
}
char    *read_to_buffer(int fd, char *curr_buffer)
{
    char    *buffer;
    size_t  bytes_read;

    if (!curr_buffer)
        curr_buffer = malloc(1);

    buffer = ft_calloc((BUFFER_SIZE + 1) , sizeof(char));
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            return(NULL);
        }
        buffer[bytes_read] = 0;
        curr_buffer = clear_buffer(curr_buffer, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (curr_buffer);
}

char    *get_next_line(int fd)
{
    static char *buffer[MAX_FD];
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer[fd] = read_to_buffer(fd, buffer[fd]);
    if (!buffer[fd]) 
        return (NULL);
    line = get_line(buffer[fd]);    
    buffer[fd] = buffer_to_next_line(buffer[fd]);
    return (line);    
}



