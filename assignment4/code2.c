#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
    struct Employee
        {
            int eid;
            char ename[20];
            int tno;
        };

void *fun(void *args)
    {

        struct Employee* s=(struct Employee*)args;

        
        printf("%d\t\t%s----------------Printed by thread %d\n",s->eid,s->ename,s->tno);
        // printf("%s\n",s->ename);


    }


int main()
    {
        pthread_t tid1,tid2;

        
        struct Employee e1;
        struct Employee e2;

        e1.tno=1;
        e1.eid=100;
        strcpy(e1.ename,"Het Shah");

        e2.tno=2;
        e2.eid=120;
        strcpy(e2.ename,"Raj Patel");

        printf("Here 2 threads are executing same function\n");
        printf("We can see details of 2 employees printed by 2 diffrent threads\n\n\n");

        printf("Employee id\tEmployee name\n\n");


        pthread_create(&tid1,NULL,fun,&e1);
        pthread_join(tid1,NULL);
        pthread_create(&tid2,NULL,fun,&e2);
        pthread_join(tid2,NULL);



    }