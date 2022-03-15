#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

int main()
	{
		int fd;
		char write_buf[60]="My name is Het Shah";
                char read_buf[60];		
	
		//fd=creat("new_file.txt",777);

		open("new_file.txt", 777);
		printf("New file created with fd=%d\n",fd);

		

		write(fd,write_buf,60);

		lseek(fd,0,SEEK_SET);

		read(fd,read_buf,60);

		printf("Read content=%s\n",read_buf);
	
		close(fd);

		return 0;
	}
