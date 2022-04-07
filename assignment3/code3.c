#include<stdio.h>
#include<pthread.h>

 pthread_t tid;

void* function(void* args)
    {
        printf("Hello, I am thread created by process\n");
        printf("My attributes are as below:\n");
        printf("Thread id=%lu\n",tid);
        //printf("Threa")
    }

int main()
    {
       
        pthread_attr_t attribute;
        size_t size;
        void *addr;
        pthread_attr_init(&attribute);

        pthread_attr_getstacksize(&attribute,&size);
        pthread_attr_getstackaddr(&attribute,&addr);
        printf("Default address = %08x\nDefault size= %d\n",addr,size);

        size_t newsize;
        void *newaddr;

         
         //newsize=100000000000000;
         newsize=50331648;
         newaddr=malloc(newsize);


        pthread_attr_setstack(&attribute,newaddr,newsize);

        pthread_create(&tid,&attribute,function,NULL);

        pthread_attr_getstack(&attribute,&addr,&size);

        printf("New address = %p\nNew size= %lu\n",addr,size);

        pthread_attr_destroy(&attribute);

        // pthread_join(tid,NULL);
        sleep(1);

       // printf()

       return 0; 
    }