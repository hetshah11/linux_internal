#include<stdio.h>
#include<string.h>

struct A
    {
       // int roll;
        char gender,name;
        float a;
        char a1,a2;
        //float height;
    };

int main()
    {
        struct A first;
        //struct student third = {103,"Hari Prasad.D",'M',5.11};

        //printf("\nRoll\tName\t\t\t\t\t\tGender\t\tHeight\n");
        // first.roll=101;
        // strcpy(first.name,"Phaneedra Kumar P");
        // first.gender='M';
        // first.height=5.6;

        printf("\nSize of struct A %3d\n",sizeof(first));

       

        return 0;
    }