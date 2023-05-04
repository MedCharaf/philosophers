#include "philo.h"
#include <stdio.h>

void* print_message() {
      // Cast the void* argument to ThreadData*
    printf("Thread \n");  // Print the thread's ID and message
    sleep(3);
    printf("ending thread\n");
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

    i = 0;
    while(i < num_of_philos ){
         if(pthread_create(&threads[i], NULL, &print_message,NULL));
         i++;
    }

        for (int i = 0; i < num_of_philos; i++) {
        pthread_join(threads[i], NULL);
    }



return 0;

}
else 
printf("check args\n");
exit(1);
}

