#include<stdio.h>
#include<unistd.h>

int main()
	{
		pid_t pid;
		pid=fork();

		if(pid<0)
			{
				fprintf(stderr,"Fork failed");
				exit(-1);
			}
		else if(pid==0)
			{
				execl("/bin/ls","ls",NULL);
			}
		else
			{
				wait(0);
				printf("child complete\n");
				exit(0);
			}

		return 0;
	}
