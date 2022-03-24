#include<stdio.h>
#include<pthread.h>
// #include<semaphore>

int shared_var=100;

pthread_mutex_t my_lock;

void* fun1(void *args)
    {
        printf("Hello! I am thread1\n");
        pthread_mutex_lock(&my_lock);
        shared_var=shared_var+5;
       // sleep(3);
        pthread_mutex_unlock(&my_lock);
        printf("Value of shared variable is incremented by 5.New value is %d\n",shared_var);
    }
void* fun2(void *args)
    {
        printf("Hello! I am thread2\n");
        pthread_mutex_lock(&my_lock);
        shared_var=shared_var-5;
        pthread_mutex_unlock(&my_lock);
        printf("Value of shared variable is decremented by 5.New value is %d\n",shared_var);
    }




int main()
    {
        pthread_t thd1,thd2;
        pthread_mutex_init(&my_lock,NULL);

        pthread_create(&thd1,NULL,fun1,NULL);
        //sleep(2);
        pthread_create(&thd2,NULL,fun2,NULL);

        pthread_join(thd1,NULL);
        pthread_join(thd2,NULL);

        exit(0);
    }