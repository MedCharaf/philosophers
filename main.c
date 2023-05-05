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
  t_mythread *mythread;
   int i = 0;
  mythread = (t_mythread*)malloc(sizeof(t_mythread));

    mythread-> times_philosopher_must_eat = 0;
   int  num_of_philos = ft_atoi_v2(argv[1]);
   pthread_t* th = malloc(sizeof(pthread_t) * num_of_philos);
     mythread[i]-> time_to_die = ft_atoi_v2(argv[2]);
     mythread[i]->time_to_eat = ft_atoi_v2(argv[3]);
     mythread[i]->time_to_sleep = ft_atoi_v2(argv[4]);
     mythread[i]-> times_philosopher_must_eat = ft_atoi_v2(argv[5]);
    pthread_mutex_init(&mutex , NULL);
    i = 0;

    while(i < num_of_philos){
        pthread_create(&th[i], NULL, &print_message,NULL);
        th[i] = 
        printf("philo %i started execution \n", i);
         i++;
    }
    i= 0;
    while( i <num_of_philos){
              pthread_join(&th[i], NULL);
                printf("philo %i finished execution \n", i);
i++;
    }

pthread_mutex_destroy(&mutex);
    printf("%d\n", incr);
}
else 
printf("check args\n");
exit(1);
}

