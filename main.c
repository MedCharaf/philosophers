#include "philo.h"
#include <stdio.h>


int main(int argc , char **argv){

if(argc == 6 ){
     int  times_philosopher_must_eat = 0;
    int num_of_philos = ft_atoi_v2(argv[1]);
     int time_to_die = ft_atoi_v2(argv[2]);
    int time_to_eat = ft_atoi_v2(argv[3]);
   int time_to_sleep = ft_atoi_v2(argv[4]);
   if(argc == 6)
        times_philosopher_must_eat = ft_atoi_v2(argv[5]);

}
else 
printf("check args\n");
exit(1);
}
