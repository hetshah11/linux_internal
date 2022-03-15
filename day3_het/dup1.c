#include<stdio.h>
#include<fcntl.h>

int main()
	{
		int fd1,fd2,fd3,fd4;

		fd1=open("linux.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);
		fd2=open("linuxnew.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);
		printf("fd of linux.txt=%d\n",fd1); 
		printf("fd of linuxnew.txt=%d\n",fd2);

		//fd3=dup(fd1);
		fd4=dup2(fd2,44);
		fd3= fcntl(fd1,F_DUPFD,10);

		printf("fd_dup of fd1=%d",fd3);
		printf("fd_dup of fd2(by dup2)=%d",fd4);


		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
		
		
	}
