#include<stdio.h>
#include<unistd.h>

int main()
	{
		printf("My process id=%d\n",getpid());

		printf("My parent pid= %d\n",getppid());

		
	}
