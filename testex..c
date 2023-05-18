void *print_message(void *arg)
{
    t_mythread *mythread = (t_mythread*)arg;
    t_mydata *mydata = mythread->mydata;
    int i = 0;
    while (i < mydata->num_of_philos) {
        pthread_mutex_lock(&mydata->forks[mythread->id]);
        pthread_mutex_lock(&mydata->forks[(mythread->id + 1) % mydata->num_of_philos]);

        printf("Philo %d is eating\n", mythread->id);
        pthread_mutex_unlock(&mydata->forks[mythread->id]);
        printf("Philo %d is thinking\n", mythread->id);
        pthread_mutex_unlock(&mydata->forks[(mythread->id + 1) % mydata->num_of_philos]);
        i++;
    }
    return NULL;
}
int main(int argc, char **argv)
{
    int i;
    t_mydata *mydata;
    t_mythread *mythread; 
    
    i = 0;
    mythread = malloc(sizeof(t_mythread));
    mydata = malloc(sizeof(t_mydata));
    if (argc == 6)
    {
        mydata->times_philosopher_must_eat = 0;
        mydata->num_of_philos = ft_atoi_v2(argv[1]);
        mydata->forks = malloc(sizeof (pthread_mutex_t) * mydata->num_of_philos);
        mydata->time_to_die = ft_atoi_v2(argv[2]);
        mydata->time_to_eat = ft_atoi_v2(argv[3]);
        mydata->time_to_sleep = ft_atoi_v2(argv[4]);
        mydata->times_philosopher_must_eat = ft_atoi_v2(argv[5]);
        i = 0;
        while (i < mydata->num_of_philos)
        {
            pthread_mutex_init(&mydata->forks[i], NULL);
            i++;
        }
        i = 0;
        while (i < mydata->num_of_philos)
        {
            mythread[i].id = i;
            mythread[i].mydata = mydata;
            pthread_create(&mythread[i].th, NULL, &print_message, &mythread[i]);
            sleep(150);
             printf("philo %i started execution \n", i);
            i++;
        }
    }
    else
    {
        printf("check args\n");
        exit(1);
    }
    return 0;
}