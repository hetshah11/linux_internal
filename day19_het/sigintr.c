#include<stdio.h>
#include<signal.h>

// void 

void sighand(int signum)
    {
        printf("Interrupt signal rec'd.. but no termination on ctrl +c\n");

        signal(SIGINT,SIG_DFL);
    }
int main()
    {
        int i;

        signal(SIGINT,sighand);

        for(i=0;;i++)
            {
                printf("%d\n",i);
                sleep(1);
            }

    }