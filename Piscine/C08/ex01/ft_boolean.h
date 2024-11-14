/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:13:49 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/19 09:31:54 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE 0
# define FALSE 1
# define EVEN(number) number % 2 == 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG  "I have an odd number of arguments.\n"
# define SUCCESS TRUE

typedef int	t_bool;

#endif
