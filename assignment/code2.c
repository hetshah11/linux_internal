#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void main()
{
    int fd1, fd2;

    char buffer_write[50] = "Hello. My name is Het Shah";
    char buffer_read[50];

    fd1 = open("het1.txt", O_RDWR | O_CREAT | O_TRUNC, 777);
    fd2 = open("het2.txt", O_RDWR | O_CREAT | O_TRUNC, 777);
    printf("File created fd: %d\n", fd1);
    printf("File created fd: %d\n", fd2);

    write(fd1, buffer_write, 50);

    // Implementation of SEEK_SET 
    lseek(fd1, 0, SEEK_SET);
    // lseek(fd1, 4, SEEK_SET);

    // lseek(fd1, -20, SEEK_END);
    // lseek(fd1, -30, SEEK_END);  

  

    read(fd1, buffer_read, 50);
    printf("data read: \n%s\n", buffer_read);
    write(fd2, buffer_read, 50);

}

