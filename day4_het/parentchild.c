#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
	{
		pid_t pid;
		int option,stat;

		while(1)
			{
				printf("Enter 1 to exex 'ls programme in child process and 0 to exit\n");

				scanf("%d",&option);
				if(!option)
					exit(0);
				printf("\n");

				if(fork()==0)
					{
						execl("/bin/ls","ls",0);
						exit(0);
					}
			}
	}
