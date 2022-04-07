#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
    {
        int shm_id;
        void *addr;
        shm_id=shmget(65,300,IPC_CREAT|0644);
            if(shm_id<0)
                printf("There is some error in getting shared memory\n\n");

        addr=shmat(shm_id,0,0);

        printf("Attached shared memory in read only mode to PAS at location %p\n\n",addr);

        printf("We are going to store some data at this shared memory\n\n");

        memcpy(addr,"Hello! Het Shah",300);
        printf("Data stored at shared memory is as below\n\n");

        // char *ptr = addr;


        // memset(ptr,'h',100);
        printf("\n%s\n\n",addr);

        printf("Now we are detaching shared memory form PAS\n\n");

        int res=shmdt(addr);
            if(res<0)
                printf("Error.....\n");

        printf("shared memory detached from PAS\n\n");

        printf("Now, If we going to access same memory location, we will get Segmentation Fault\n");

        printf("\n%s\n",addr);
        

        return 0;






    }