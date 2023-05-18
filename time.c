 

#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    printf("Current time: %ld seconds and %d microseconds\n", current_time.tv_sec, current_time.tv_usec);

    return 0;
}

// time when program start
// time now (printf("%ld" , time_now() - time when program start))
