#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
    {
        pid_t pid;
        char buf[100];
        pid=fork();
            if(pid==0)
                {
                    int fd;
                    if(fd==-1)
                    printf("something went wrong\n");
                    fd=open("hello.txt", O_CREAT | O_RDWR, 777);
                    read(fd,buf,100);
                    printf("data read from hello.txt is\n\n%s\n",buf);
                    close(fd);
                    exit(0);
                }
            else
                wait(0);

            return 0;
    }