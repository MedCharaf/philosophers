#ifndef philo_h
#define philo_h

#include "libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_mythread
{
    int *id;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int times_philosopher_must_eat;

} t_mythread;

int ft_atoi_v2(char *str);
long calculate_number(char *str, int sign);


#endif