/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:01:19 by sraiha            #+#    #+#             */
/*   Updated: 2024/10/29 10:53:12 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
    if((c >= 65 && 90 <= c) || (c >= 97 && 122 <= c))
        return 1;
    else
        return 0;   
}