#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
    {
        int i;
        printf("\nfile name:%s\n",argv[0]);
        printf("\nTotal number of arguments: %d\n",argc);
        printf("\nArguments passed:\n");

        for(i=1;i<argc;i++)
            {
                printf("%s ",argv[i]);
            }
        printf("\n");
    }