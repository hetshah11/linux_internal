#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

int main()
{
    // pthread_t thd;

    // pthread_attr_t attribute;
    int policy;
    struct sched_param parameter;

    pthread_getschedparam(pthread_self(), &policy, &parameter);

    printf("By default policy=%d\nBy default priority=%d\n", policy, parameter.sched_priority);

    printf("\n\nNow we are going to change policy and priority of current thread\n\n");
    policy = SCHED_RR;
    parameter.sched_priority = 20;

    pthread_setschedparam(pthread_self(), policy, &parameter);

    pthread_getschedparam(pthread_self(), &policy, &parameter);

    printf("When we are normal user we can't change policy and priority of any process\n");
    printf("For that we have to login with root user id\n");

    printf("\n\nPolicy and priority of thread is changed\n\n");

    printf("new policy=%d\nnew priority=%d\n", policy, parameter.sched_priority);

    printf("\nHere new policy is 2, which is internally round robin\n");

    exit(0);
}