#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
    {
        printf("This is current flow\n");
        printf("The flow is changed now\n");
        execl("/usr/bin/pstree","",NULL);

        exit(0);
    }