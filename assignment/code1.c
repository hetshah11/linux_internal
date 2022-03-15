#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
	{
		int fd1,fd2;
		char buf[60]="Hello! I am het shah...........";
		char buf_extra[60];
		
		fd1=open("input.txt",O_RDWR | O_CREAT | O_TRUNC,777);
		fd2=open("output.txt",O_RDWR | O_CREAT | O_TRUNC,777);
		
		write(fd1,buf,60);

		lseek(fd1,0,SEEK_SET);


		read(fd1,buf_extra,60);
		write(fd2,buf_extra,60);

		close(fd1);
		close(fd2);
	
		return 0;

		
	}
