#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
  int fd;
  fd = open("/home/het/Desktop/linux_internal/assignment2/file", O_RDONLY, 777);
  printf("inherit file descriptor: %d\n",fd);  

  return 0;
}