#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

pthread_spinlock_t spinlock;


void* fun1(void* args)
    {
        printf("Hello, I am Thread 1\n\n");
        

        pthread_spin_lock(&spinlock);
        printf("Thread 1 acquired lock\n\n");

        printf("This part of thread 1 is secured by spinlock\n\n");
        printf("Now thread 1 is going to wait and thread 2 will try to acquire a lock\n\n");
        sleep(6);

        printf("Thread 1 resumes now\n\n");
        pthread_spin_unlock(&spinlock);
        printf("Thread 1 released lock\n\n");
    }

void *fun2(void * args)
    {
        printf("Thread 2 is trying to acquire a lock but fails because thread 1 has already acquired it\n\n");
        pthread_spin_lock(&spinlock);
        printf("After releasing by thread 1, Thread 2 acquired lock succesfully\n\n");

        pthread_spin_unlock(&spinlock);
        printf("Thread 2 released lock succesfully\n\n");

    }

int main()
    {
        pthread_t thd1,thd2;
        pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE);

        pthread_create(&thd1,NULL,fun1,NULL);
        // pthread_join(thd1,NULL);
        sleep(1);
        pthread_create(&thd2,NULL,fun2,NULL);
        sleep(1);

        pthread_join(thd1,NULL);
        pthread_join(thd2,NULL);
        printf("Main ends here\n\n");

        return 0;


    }