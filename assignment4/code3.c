#include <stdio.h>
#include <pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *initialization_code()
{
    printf("\n\n-------------------- INITIALIZATION CODE------------------\n");
    printf("\nThis function will be called only once\n");
    printf("Hello, After calling first time, the value of once variable will be changed\n");
    printf("So, next time, it won't be called\n\n");
    printf("----------------INITIALIZATION CODE ENDS-----------------\n");
}

void *function(void *args)
{
    int m;
    m = (int)args;
    printf("\nHello from thread %d\n", m);
    pthread_once(&once, initialization_code);

    printf("\nthread %d terminated\n\n\n", m);
}

int main()
{

    pthread_t thread1, thread2, thread3, thread4;

    pthread_create(&thread1, NULL, function, (void *)1);
    pthread_create(&thread2, NULL, function, (void *)2);
    pthread_create(&thread3, NULL, function, (void *)3);
    pthread_create(&thread4, NULL, function, (void *)4);

    pthread_join(thread1, NULL);

    pthread_join(thread2, NULL);

    pthread_join(thread3, NULL);

    pthread_join(thread4, NULL);
    printf("\nExit for main process\n\n");

    printf("Here we can see initialization code is executed by only one thread\n\n");

    printf("Here sequence of thread may be differnt because we can't determine which thread will be executed first\n ");
    // pthread_exit(NULL);

    return 0;
}
