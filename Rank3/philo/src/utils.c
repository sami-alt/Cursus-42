/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 08:23:33 by sraiha            #+#    #+#             */
/*   Updated: 2025/04/16 13:19:30 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_is_space( char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}


int	ft_atoi(const char *str)
{
	long long		flow_check;
	long long		res;
	int				sign;

	res = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '1' && *str <= '9' ))
	{
		flow_check = res * 10 + (*str++ - '0');
		if (flow_check / 10 != res && sign < 0)
			return (0);
		else if (flow_check / 10 != res && sign > 0)
			return (-1);
		res = flow_check;
	}
	return ((int)res * sign);
}

long    get_time(void)
{
    struct  timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void    philo_sleep(long milliseconds)
{
    long    start = get_time();
    
    while (get_time() - start < milliseconds)
        usleep(100);
}

void 	print_status(t_philos *philospher, char *status)
{
	pthread_mutex_lock(&philospher->data->write_lock);
	printf("%ld %d %s\n", get_time() - philospher->data->start_time, philospher->id, status);
	pthread_mutex_unlock(&philospher->data->write_lock);
}