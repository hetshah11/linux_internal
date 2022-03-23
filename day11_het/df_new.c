#include<stdio.h>
#include<stdlib.h>

void buggy(int *p)
    {
        p[0]=10;
        free(p);
    }
int main()
    {
        int *ptr,*ptr1,*ptr2;
        ptr1=NULL;
        ptr=(int*)malloc(4);
        //buggy(ptr);
         //free(ptr);
         *ptr=20;
         *ptr1=20;
        *ptr2=20;
        printf("value=%d",*ptr2);

        
    }