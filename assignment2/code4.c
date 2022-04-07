#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    printf("This is routine flow\n");
    printf("The flow is being changed\n");

    execl("/home/het/Desktop/c++ git/day5_het/demo.o",NULL);

    printf("This part should not be executed\n");
    exit(0);
}