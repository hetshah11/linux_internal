#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

void callback1(void)
	{
		printf("Callback1 function called\n");
	}
void callback2(void)
	{
		printf("Callback2 function called\n");
	}
void callback3(void)
	{
		printf("Callback3 function called\n");
	}


int main()
	{
		printf("registering callback1\n");
		atexit(callback1);
		printf("registering callback2\n");
		atexit(callback2);
		printf("registering callback3\n");
		atexit(callback3);


		printf("main() exiting now...\n");

		exit(0);

		//_exit(0);
	}
