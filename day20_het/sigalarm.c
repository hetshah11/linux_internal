#include<signal.h>

void sighand(int signum)
    {
        printf("%d\n",signum);
        // printf("I have to wake up my boss now\n");
        printf("I have received ctrl+c\n");
    }

int main()
    {
        signal(SIGINT,sighand);
        // alarm(5);

        // sleep(10);
        while(1)
            {

            }
    }