#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


int main()
    {
        int pid,pid1;
        //printf("This task is done by main process\n");
        pid=fork();
        if(pid==0)
            {
                printf("This task is done by 1st child process\n");
            }
        else    
            wait(0);
        pid1=fork();
        
        if(pid1==0)    
            {
                printf("This task is done by 2nd child process\n");
                
            }
         else    
            wait(0);
        //printf("End of main proces\n");
            exit(0);
    }

