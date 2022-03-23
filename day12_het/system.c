#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
    {
        char buf_comm[6];
        strcpy(buf_comm,"ls -l");

        printf("system() library function uses fork() to create a child process\n");
        printf("child process executes execl() which loads and run new programme provided by system() argument");

        int a=system(NULL);
        int b=system(buf_comm);
        printf("\n\n%d\n",a);
        printf("\n\n%d\n",b);
        return 0;
    }