#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data {
    int             num_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             max_meals;
    pthread_mutex_t *forks;
    pthread_mutex_t write_lock;
    pthread_mutex_t death_lock;
    bool            simulation_ended;
    long            start_time;
} t_data;

typedef struct s_philo {
    int             id;
    pthread_t       thread;
    int             meals_eaten;
    long            last_meal_time;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data          *data;
} t_philo;

// Function prototypes
int     parse_args(int ac, char **av, t_data *data);
int     init_resources(t_data *data, t_philo **philos);
int     launch_threads(t_data *data, t_philo **philos);
void    clean_exit(t_data *data, t_philo *philos, int exit_code);
void    print_status(t_philo *philo, char *msg);
long    get_time(void);

#endif