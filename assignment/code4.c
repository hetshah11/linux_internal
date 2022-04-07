#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
	{
		int fd1,fd2;
		char buf_write[60]="Hello! I am het shah...........";
		char buf_read[60];
		
		fd1=open("input.txt",O_RDWR | O_CREAT | O_TRUNC,777);
		printf("File opened with fd=%d\n",fd1);
		
		fd2=open("output.txt",O_RDWR | O_CREAT | O_TRUNC,777);
		printf("File opened with fd=%d\n",fd2); 	
		
		write(fd1,buf_write,60);

		lseek(fd1,0,SEEK_SET);


		read(fd1,buf_read,60);
		printf("Data written in file output.txt\n%s");
		write(fd2,buf_read,60);

		close(fd1);
		close(fd2);
	
		return 0;

		
	}
