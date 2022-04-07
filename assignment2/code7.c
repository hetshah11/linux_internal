#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
    {
        pid_t pid;
        pid=fork();

        if(pid==0)
            {
                printf("Hello, I am child,my pid is %d and my parent id is %d\n",getpid(),getppid());
                printf("Child is executing ls command\n");
                execl("/bin/ls","ls","-l",NULL);
                exit(0);
            }
        else
            wait(0);

            return 0;

    }