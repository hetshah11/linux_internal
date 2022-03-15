#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
	{	
		int pid;
		int status;

		printf("parent: %d\n",getpid());

		pid=fork();

		if(pid==0)
			{
				printf("child %d\n",getpid());
				sleep(2);
				exit(0);
			}

		printf("Parent reporting exit of child whose pid= %d",waitpid(pid,&status,0));

		return 0;
	}
