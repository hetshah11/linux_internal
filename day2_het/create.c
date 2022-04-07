#include<stdio.h>
#include<fcntl.h>

int main()
	{
		int fd1,fd2,fd3;
		fd1=creat("one.txt",777);
		fd2=creat("two.txt",777);
		fd3=creat("three.txt",777);

		printf("file 1 id: %d\n",fd1);
		printf("file 2 id: %d\n",fd2);
		printf("file 3 id: %d\n",fd3);

		printf("fd return by open %d",open("one.txt",O_RDWR | O_CREAT, 777));
		printf("fd return by open %d",open("two.txt",O_RDWR | O_CREAT, 777));
		printf("fd return by open %d",open("three.txt",O_RDWR | O_CREAT, 777));

		close(fd1);
		close(fd2);
		close(fd3);

		return 0;
	}
