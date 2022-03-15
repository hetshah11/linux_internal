#include<stdio.h>
#include<unistd.h>


int main()
		{
			pid_t pid;
			printf("Current process pid=%d\n",getpid());
			pid=vfork();
		
			if(pid)
			{
				printf("parent process id=%d\n",getpid());
			}
			
			else
			{
				sleep(5);
				printf("child process pid=%d\n",getpid());
			}
			exit(0);

			return 0;
		}

