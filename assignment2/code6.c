#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

void fun1(void)
	{
		printf("This function is registered first, but will execute last\n");
	}
void fun2(void)
	{
		printf("This function is registered second, and will execute second\n");
	}
void fun3(void)
	{
		printf("This function is registered last, but will execute fisrt\n");
	}


int main()
	{
		printf("registering fun1\n");
		atexit(fun1);
		printf("registering fun2\n");
		atexit(fun2);
		printf("registering fun3\n");
		atexit(fun3);



		printf("main() exiting now...\n");

        printf("Function will be called in reverse order\n");

		exit(0);

		//_exit(0);
	}