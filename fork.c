#include<stdio.h>
#include<unistd.h>

int main()
    {
        int n;
        int i;
        int pid;

        printf("Main process pid=%d\n",getpid());

        printf("Enter number\n");
        scanf("%d",&n);

        for(i=1;i<=n-1;i++)
            {
                pid=fork();

                if(pid==0)
                    {
                        printf("\nThis is child process %d and pid=%d and parent process id=%d \n",i,getpid(),getppid());
                        exit(0);
                    }
                else
                    {
                        sleep(1);
                        continue;
                    }
                

            }
            wait(0);

            return 0;
    }