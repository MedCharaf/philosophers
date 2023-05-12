#ifndef philo_h
#define philo_h

#include "libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// typedef struct t_mythread s;
struct s_mydata;

typedef struct s_mythread
{
    int id;
    pthread_t th;
    struct s_mydata *mydata;
} t_mythread;

typedef struct s_mydata
{
    int num_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int times_philosopher_must_eat;
    pthread_mutex_t *forks;
    t_mythread *mythread;
} t_mydata;



int ft_atoi_v2(char *str);
long calculate_number(char *str, int sign);


#endif