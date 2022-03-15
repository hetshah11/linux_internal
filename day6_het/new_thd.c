#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void function()
	{
		pthread_detach(pthread_self());
		printf("Hello, I am thread"); 
	}
int main()
	{
		pthread_t thread;
		
		pthread_create(&thread,NULL,function,NULL);
		printf("This is main code\n");
		pthread_exit(NULL);		//we can use pthread_join() also
		//pthread_exit terminates the main process 
	}

/*thread may be pending requests at this point
Just exit the main thrwad/process - not the whole programme- so that reamining requests that may still be processed can continue*/
