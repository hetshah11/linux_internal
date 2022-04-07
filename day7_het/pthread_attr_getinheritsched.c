
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


void *Proc(void *param)
{
sleep(3);
return 0;
}





int main(int argc, char *argv[])
	{
		pthread_attr_t Attr;
		pthread_t Id;
		int err,info;

		pthread_attr_init(&Attr);
		pthread_attr_getinheritsched(&Attr,&info);

		switch(info)
			{
				case PTHREAD_INHERIT_SCHED:
					printf("\nSCHED\n");
					break;

				case PTHREAD_EXPLICIT_SCHED:
					printf("\nEXPLICIT\n");
					break;
			}

		pthread_attr_setinheritsched(&Attr,PTHREAD_EXPLICIT_SCHED);
		pthread_attr_getinheritsched(&Attr,&info);

		switch(info)
			{
				case PTHREAD_INHERIT_SCHED:
					printf("\nSCHED\n");
					break;

				case PTHREAD_EXPLICIT_SCHED:
					printf("\nEXPLICIT\n");
					break;
			}

		printf("Process creating thread whose schd policy ");
		
		

		pthread_create(&Id,&Attr,Proc,NULL);
		
		return 0;
		
	}
