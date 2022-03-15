#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *PrintHello(void *threadid)
	{
		printf("\nHello World!\n");
		while(1);
	}

int main()
	{
		pthread_t thread;
		int rc,t=0;

		printf("Cretaing thread\n");

		rc = pthread_create(&thread,NULL,PrintHello,NULL);
		printf("\nThread ID: %u",thread);
		sleep(5);
		t=pthread_cancel(thread);

		if(t==0)
			{
				printf("\nCanceled thread\n");
			}
		printf("\nThread ID: %u\n",thread);
	}
