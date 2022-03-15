#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
	{
		int fd,len;
		int x;
		char write_buf[60]="Linux kernel new programme ?,wow het";

		fd= open("linuxabc.txt",O_CREAT | O_RDWR | O_TRUNC, 0777);
		
		write(fd,write_buf,60);

		close(fd);

		return 0;
	}
