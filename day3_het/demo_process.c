#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main()
	{
		printf("Het\n");
		fork();
		fork();
		printf("Het Shah\n");
		while(1);

	
	}
