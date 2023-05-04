#include "philo.h"
#include <stdio.h>

int incr =0;
  pthread_mutex_t mutex;
void* print_message() {
int i  = 0;
    while(i <1000000){
      pthread_mutex_lock(&mutex);
        incr++;
      pthread_mutex_unlock(&mutex);
    i++;
    }

    return NULL;
}

int main(int argc , char **argv){

if(argc == 6 ){
  
    //  int  times_philosopher_must_eat = 0;
    int num_of_philos = ft_atoi_v2(argv[1]);
//      int time_to_die = ft_atoi_v2(argv[2]);
//     int time_to_eat = ft_atoi_v2(argv[3]);
//    int time_to_sleep = ft_atoi_v2(argv[4]);
//    times_philosopher_must_eat = ft_atoi_v2(argv[5]);
   int i = 0;
    pthread_t threads[num_of_philos];
    pthread_mutex_init(&mutex , NULL);
    i = 0;
    while(i < num_of_philos ){
        pthread_create(&threads[i], NULL, &print_message,NULL);
        pthread_join(threads[i], NULL);
         i++;
    }
pthread_mutex_destroy(&mutex);
    printf("%d\n", incr);
}
else 
printf("check args\n");
exit(1);
}

