#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
//#include <sys/types.h>
//#include <sys/stat.h>


int main()
	{
		int fd1;
		char buf[60]="Hello ! HOw are you?";
		//fd1=creat("het.txt",777);

		//fd2=creat("data.txt",777);

		fd1=open("het.txt",O_RDWR | O_CREAT | O_TRUNC,777);
		//fd2=open("data.txt",O_RDWR,777);
		
		
		//int k=;
		printf("%ld\n", write(fd1,buf,60));
		

		
		
		//ssize_t m=read(fd1,buf,60);
		//printf("%ld\n",m);

		close(fd1);
		//close(fd2);
		return 0;
		
	}
