#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

static int threadFunc(void *arg)
	{
		char *s =(char*)arg;
		printf("%s\n",s);
		//sleep(5);
		//void *ptr;
		//int i=strlen(s);
		//ptr=&i;
		//return i;
		return (void*)strlen(s);
		return 0;
	}

int main(int argc, char *argv[])
	{
		pthread_t t1;
		void *res;
		int s;
		pthread_create(&t1,NULL,threadFunc,"Hello");
		printf("Message from main()\n");

		sleep(3);	
		pthread_join(t1,&res);
		printf("Thread returned %ld\n",(long)res);
		exit(0);
	}
