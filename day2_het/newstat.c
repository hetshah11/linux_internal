#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
	{
		struct stat s1;
		int fd;
		stat("lssek.c",&s1);
	}
