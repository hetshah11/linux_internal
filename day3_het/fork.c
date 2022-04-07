#include<stdio.h>
#include<unistd.h>

int main()
	{
		int pid_1;

		printf("Current process id=%d\n",getpid());

		pid_1=fork();


		if(pid_1==0)
			{
				printf("New child process pid=%d\n",getpid());
				printf("new child process ppid=%d\n",getppid());
			}

		else
			{
				sleep(3);
				printf("parent process id=%d\n",getpid());
				printf("parent parent's process ppid=%d\n",getppid());

			}

		while(1);
		return 0;
	}
