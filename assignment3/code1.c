#include<stdio.h>
#include<pthread.h>

int x=10;
void function1(void* arg)
    {
        x=x+1;
        printf("value of x=%d\n",x);
        printf("Thread 1 suspends....\n\n");
        sleep(3);
        printf("Thread 1 resumes...\n\n");
        x=x+10;
        //printf("value of x=%d\n",x);
        
    }
void function2(void *arg)
    {
        x=x-5;
        printf("\nHere thread 2 change value of x so,there will be inconsistency in thread 1\n\n\n");
    }


int main()
    {
        pthread_t thd1,thd2;

        pthread_create(&thd1,NULL,function1,NULL);
        sleep(2);
        pthread_create(&thd2,NULL,function2,NULL);
        pthread_join(thd1,NULL);
        pthread_join(thd2,NULL);
        //sleep(1);
        
        printf("\nvalue of x=%d\n",x);

        printf("\n\n\nHere thread 1 is supposed to set value of x to 21, but due to inconsistency, we are getting value 16\n ");
        exit(0);
    }