#include<stdio.h>
#include<pthread.h>

void* function(void* args)  
    {
        printf("Hello! This is thread\n");
        printf("thread is being cancelled\n");
        int ret=pthread_cancel(pthread_self());
        if(ret)
            printf("thread is not cancelled\n");
        else
            printf("thread is cancelled succesfully\n");
        printf("This part should not be executed\n");
       
    }

int main()
    {
        pthread_t tid;

        pthread_create(&tid,NULL,function,NULL);
        pthread_join(tid,NULL);

        exit(0);


    }