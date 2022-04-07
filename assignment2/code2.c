#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void fun1()
    {
        printf("This is Task 1\n");
        printf("This task is done by process 1\n");

    }
void fun2()
    {
        printf("This is Task 2\n");
        printf("This task is done by process 2\n");

    }

int main()
    {
        int i;
        pid_t pid;
        //printf("Hello , I am main process\n");
        
                pid=fork();
                if(pid==0)
                {
                    printf("Hello, I am doing 1st task,my pid is %d and my parent id is %d\n",getpid(),getppid());
                    fun1();
                    exit(0);
                }
                else    
                    wait(0);

                    pid=fork();
                
                    if(pid==0)
                        {
                            printf("Hello, I am printing 2nd task,my pid is %d and my parent id is %d\n",getpid(),getppid());
                            fun2();
                            exit(0);
                            
                        }

                
                    else
                    wait(0);
                
            
                
            
           
            return 0;
        
        
        
    }
