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
char    *clear_buffer(char *result, char *buffer)
{
    char *temp;

    temp = ft_strjoin(result, buffer);
    free(result);
    return (temp);
}

char    *get_line(char *buffer)
{
    char *line;
    size_t line_len;

    printf("get_line called\n");
    line_len = 0;
    printf("line_len set\n");
    int check = buffer[line_len] != '\0' && buffer[line_len] != '\n';
    printf("check done\n");
    while (check)
    {
        line_len++;
        printf("check again\n");
        check = buffer[line_len] != '\0' && buffer[line_len] != '\n';
        printf("check again done\n");
    //    printf("get 1");
    }
    printf("%ld", line_len);
    printf("checks done\n");
    printf("checks really done\n");
    line = malloc((line_len ) * sizeof(char));
    printf("malloc done\n");
    printf("malloc really done\n");
    if (!line)
        return (NULL);
    line_len = 0;
    while (buffer[line_len] != '\0' && buffer[line_len] != '\n')
    {   
     //   printf("get 2");
        line[line_len] = buffer[line_len];
        line_len++;
    }
    if (buffer[line_len] != '\0' && buffer[line_len] == '\n')
    {
        line[line_len++] = '\n';
     //   printf("get 3");
    }
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
    new_buffer = malloc((ft_strlen(curr_buffer) - i + 1) * sizeof(char));
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

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
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
    int  check;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer[fd] = read_to_buffer(fd, buffer[fd]);
    printf("1\n");
    printf("before check\n");
    check = !buffer[fd];
    printf("after check\n");
    if (check) {
        printf("return null\n");
        return (NULL);
    }
    printf("get line\n");
    printf("fd %ld\n", fd);
    char* buffer_fd = buffer[fd];
    printf("got buffer fd\n");
    line = get_line(buffer_fd);
    printf("2\n");     
    buffer[fd] = buffer_to_next_line(buffer[fd]);
    printf("3\n");
    return (line);    
}




