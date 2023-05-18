#include "philo.h"

//pthread_mutex_t mutex;

long t_now(t_mydata *mydata){
    long time_now;
    gettimeofday(&mydata->time,NULL);
    time_now = mydata->time.tv_sec*1000 +mydata->time.tv_usec /1000 ;
    return (time_now);
}

void *print_message(void *arg)
{
    t_mythread *mythread = (t_mythread*)arg;
    t_mydata *mydata = mythread->mydata;
    while (1) 
    {
        printf("%ld %d is thinking\n", t_now(mydata) - mydata->t_start, mythread->id);
        pthread_mutex_lock(&mydata->forks[mythread->id]);
        printf("%ld %d has taken a fork\n", t_now(mydata) - mydata->t_start , mythread->id);
        pthread_mutex_lock(&mydata->forks[(mythread->id + 1) % mydata->num_of_philos]);
        printf("%ld %d has taken a fork\n", t_now(mydata) - mydata->t_start , mythread->id);
        printf("%ld %d is eating\n", t_now(mydata) - mydata->t_start , mythread->id);
        // last–eat = t_now();
        //kimot sleep bzf > time to die
        usleep(mydata->time_to_eat * 1000);
        pthread_mutex_unlock(&mydata->forks[mythread->id]);
        pthread_mutex_unlock(&mydata->forks[(mythread->id + 1) % mydata->num_of_philos]);
        printf("%ld %d is sleeping\n", t_now(mydata) - mydata->t_start , mythread->id);
        usleep(mydata->time_to_sleep * 1000);
    }
    return NULL;
}
int main(int argc, char **argv)
{
    int i;
    t_mydata *mydata;
    t_mythread *mythread;
    
    mydata = malloc(sizeof(t_mydata));

    if (argc == 6)
    {
        mydata->times_philosopher_must_eat = 0;
        mydata->num_of_philos = ft_atoi_v2(argv[1]);
        mydata->time_to_die = ft_atoi_v2(argv[2]);
        mydata->time_to_eat = ft_atoi_v2(argv[3]);
        mydata->time_to_sleep = ft_atoi_v2(argv[4]);
        mydata->times_philosopher_must_eat = ft_atoi_v2(argv[5]);
        
        mydata->t_start = t_now(mydata);
        mydata->forks = malloc(sizeof(pthread_mutex_t) * mydata->num_of_philos);
        mythread = malloc(sizeof(t_mythread) * mydata->num_of_philos);
        i = 0;
        while (i < mydata->num_of_philos)
        {
            pthread_mutex_init(&mydata->forks[i], NULL);
            mythread[i].id = i;
            mythread[i].mydata = mydata;
            i++;
        }

        i = 0;
        while (i < mydata->num_of_philos)
        {
            pthread_create(&mythread[i].th, NULL, &print_message, &mythread[i]);
            usleep(150);
            i++;
        }
    }
    else
    {
        printf("check args\n");
        exit(1);
    }
    while (1){}
    // check if last_eat - t_now > time_die 
    // free(mydata->forks);
    // free(mydata);
    // free(mythread);
    
    return 0;
}