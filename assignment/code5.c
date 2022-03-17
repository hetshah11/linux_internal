#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    char array[4000];
    struct stat st1;

    int fd;

    fd = open("het.txt", O_CREAT | O_RDWR, 777);

    write(fd, array, 4000);
    stat("het.txt", &st1);
    
    printf("size: %lu", st1.st_size);

  return 0;
}

