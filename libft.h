/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:33:49 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/04 15:36:41 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

//remove down
#include <stdio.h>
#include <string.h>

//libft
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int     ft_tolower(int c);
int     ft_toupper(int c);
size_t      ft_strlen(const char *s);
void    *memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
void    *ft_memset(void *s, int c, size_t n);
void    *ft_memmove(void *dest, const void  *src, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_memset(void *s, int c, size_t n);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s);
size_t      ft_strlcat(char *dst, const char *src, size_t size);
size_t      strlcpy(char *dest, const char *src, size_t  size);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
char    *ft_strrchr(const char *s, int c);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t count, size_t size);
signed long long	ft_atoi(char *str); //needs work!!!

//additionals
char    *ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_strjoin(const char* s1, const char *s2);
char    *ft_strtrim(char const *s1, const char *set);
char    **ft_split(const char *s, char c);
char    *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int, char*));
void    ft_putchar_fd(char c, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);
void    ft_putstr_fd(char *s, int fd);

//bonus
typedef struct s_list
{
    void                *content;
    struct  s_list      *next;
    
} t_list;
t_list  *ft_lstnew(void *content);


#endif