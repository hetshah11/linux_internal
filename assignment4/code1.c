#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void *fun(void *arg)
    {
        printf("This task is done by thread\n");
        sleep(3);
        printf("This part is executing after main process termination\n");
        printf("Thread task ends here\n");
    }

int main()
    {
        pthread_t thd;

        pthread_create(&thd,NULL,fun,NULL);
        // pthread_detach(thd);
        sleep(1);
        printf("Main ends here\n");
        pthread_exit(NULL);

        // exit(0);
    }
