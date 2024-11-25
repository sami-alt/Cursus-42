/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 10:46:42 by sraiha            #+#    #+#             */
/*   Updated: 2024-11-20 10:46:42 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEST_LINE_H 
# define GET_NEST_LINE_H

#include <stdlib.h>
//#include <io.h> // remember to remove
#include <unistd.h>
#include <stddef.h>

#define MAX_FD 1024

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char    *read_to_buffer(int fd, char *curr_buffer);
char    *get_next_line(int fd);
char    *ft_strchr(char *s, int c);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(const char *s1, const char *s2);
void    *ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);

#endif