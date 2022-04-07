#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(void)
    {
        printf("Server - Listening\n");

        int code= mkfifo("cli_ser_fifo",0764);

        if(code==-1)
            perror("mkfifo returned an error - file may already exist");

        int fd= open("cli_ser_fifo",O_RDONLY);
        if(fd==-1)
            {
                perror("cannot open fifo for read");
                return 0;
            }
        printf("FIFO OPEN");

        char serverrcv[100];
        memset(serverrcv,0,100);

        int res;
        char Len;

        while(1)
            {
                // res=read(fd,&Len,1);
                // printf("%d\n",res);
                // if(res==0)
                    // break;
                int m=read(fd,serverrcv,100);


                printf("Server received:%s\n",serverrcv);
                    if(m!=0)
                        break;
            }

        printf("EOF Reached\n");

        close(fd);

        printf("FIFO closed\n");

        return 0;
    }