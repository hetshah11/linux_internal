#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
	{
		int fd;
		char buf[300];
		int res;
		fd=open("write_fd.c", O_CREAT|O_RDWR,777);
		printf("%d\n",fd);
		read(fd,buf,300);

		if(fd<0)
			{
				printf("file is not opened or created ");
				
			}
		else
			{
				
				printf("read data from file is %s",buf);
			}
	}
