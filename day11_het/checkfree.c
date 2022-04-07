#include<stdio.h>
#include<stdlib.h>

void buggy()
    {
        int *intptr;
        intptr=(int*)malloc(sizeof(int));

        *intptr=100;
        printf("value at intptr= %d\n",(*intptr));
        free(intptr);

        *intptr=99;
        //free(intptr);
    }

    int main()
        {
            buggy();
            return 0;
        }