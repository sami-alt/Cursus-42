/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:07:28 by sraiha            #+#    #+#             */
/*   Updated: 2024/12/13 15:58:58 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *counter);
void	ft_putstr(char *str, int *counter);
void	ft_putptr(void *ptr, int *counter);
void	ft_putnbr(int nbr, int *counter);
void	ft_putunsigned(unsigned int nbr, int *counter);
void	ft_puthex(unsigned int num, int *counter, char *base);
char	*ft_put_num_by_base(unsigned long long num, char *base);

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define DECIMAL "0123456789"

#endif
