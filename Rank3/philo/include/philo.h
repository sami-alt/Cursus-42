/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:11:57 by sraiha            #+#    #+#             */
/*   Updated: 2025/04/16 12:39:22 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef philos_H
# define philos_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_data
{
    int             number_of_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             max_meals;
    long            start_time;
    bool             simulation_ended;
    pthread_mutex_t death_lock;
    pthread_mutex_t *forks;
    pthread_mutex_t write_lock;
} t_data;

typedef struct s_philos
{  
    int id;
    pthread_t thread;
    int meal_eaten;
    long last_meal_eaten;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *rigth_fork;
    t_data *data;
} t_philos;

//core
int     parse_arguments(int ac, char **av, t_data *data);
int     init_resources(t_data *data, t_philos **philos);
void    free_resources(t_data *data, t_philos *philos);

//philo actions
void    *philosopher_routine(void *arg);
void    take_forks(t_philos *philosopher);
void    eat(t_philos *philosopher);
void    drop_forks(t_philos *philosopher);

//monitor
void    *monitor_routine(void *arg);
int     check_meal_completion(t_data *data, t_philos *philosopher);
int    check_philosopher_death(t_philos *philosopher, t_data *data);

//utils
int     ft_atoi(const char *str);
long    get_time(void);
void    philo_sleep(long milloseconds);
void    print_status(t_philos *philosopher,char *status);

void    free_resources(t_data *data, t_philos *philos);
void clean_exit(t_data *data, t_philos *philos, int exit_code);

void clean_threads(t_philos *philos, int created_count);
int  launch_threads(t_data *data, t_philos **philos);

bool stop_simulation(t_philos  *philos);

#endif