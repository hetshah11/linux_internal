#include<stdio.h>
#include<unistd.h>

int main()
	{

		int ret;

		//ret=execl("/usr/bin/vi","vi","info1.txt",0);
		//if(ret==-1)
		//	printf("Execl returned error %d\n",ret);
		
		printf("I am going to execute an 'ls programme\n");

		execl("/bin/ls","ls","-lh",0);
		//execl("/bin/vfork")

		printf("I exexuted ls programme\n");
		printf("I exexuted ls programme\n");
		printf("I exexuted ls programme\n"); 

		return 0;
	}
