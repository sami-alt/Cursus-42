/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:11:57 by sraiha            #+#    #+#             */
/*   Updated: 2025/04/15 15:31:11 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
    int             number_of_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             max_meals;
    long            start_time;
    int             simulation_ended;
    pthread_mutex_t death_lock;
    pthread_mutex_t *forks;
    pthread_mutex_t lock;
} t_data;

typedef struct s_philosophers
{  
    int id;
    pthread_t thread;
    int meal_eaten;
    long last_meal_eaten;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *rigth_fork;
    t_data *data;
} t_philosophers;

//core
int     parse_arguments(int ac, char **av, t_data *data);
int     init_resources(t_data *data, t_philosophers **philosophers);
void    free_resources(t_data *data, t_philosophers *philosophers);

//philo actions
void    *philosopher_routine(void *arg);
void    take_forks(t_philosophers *philosopher);
void    eat(t_philosophers *philosopher);
void    drop_forks(t_philosophers *philosopher);

//monitor
void    *monitor(void *arg);
int     check_meal_completion(t_data *data, t_philosophers *philosopher);
void    check_philosopher_death(t_philosophers *philosopher, t_data *data);

//utils
int     ft_atoi(const char *str);
long    get_time(void);
void    philo_sleep(long milloseconds);
void    print_status(t_philosophers *philosopher,char *status);

void    free_resources(t_data *data, t_philosophers *philosophers);
void clean_exit(t_data *data, t_philosophers *philos, int exit_code);

void clean_threads(t_data *data, t_philosophers *philos, int created_count);
int  launch_threads(t_data *data, t_philosophers **philos);

#endif