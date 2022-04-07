#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>

void function(void *args)
    {
        printf("\nHello, I am thread\n");
        printf("My thread id=%lu\nprocess id =%lu",pthread_self(),getpid());
    }

int main()
    {
        pthread_t tid;

        printf("Hello, I am main process\n");
        printf("Thread is being created\n");
        pthread_create(&tid,NULL,function,NULL);
        pthread_join(tid,NULL);

        return 0;


    }