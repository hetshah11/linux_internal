#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>



#define MY_KEY 199
#define SHM_SIZE 0x1000
#define MSG_LEN 256
#define RESP_MSG_START 256



int main()
{
int semId,shmId;
char *pShm;
struct sembuf smop;



semId = semget(MY_KEY,1,0660);
if(semId < 0)
{
printf("Could not create semaphore\n");
return(1);
}
else
{
printf("Opened a semaphore ID is: %d\n",semId);
}



shmId = shmget(MY_KEY,SHM_SIZE,0660);
if(shmId<0)
{
printf("Could not create shared segment\n");
return(2);
}



pShm = shmat(shmId,NULL,0);
if(!pShm)
{
printf("Could not attach mempry segment.\n");
return(3);
}



while(1)
{
printf("Client: Enter some request message to send to server\n");
fgets(pShm,MSG_LEN,stdin);
smop.sem_num = 0;
smop.sem_op = 1;
smop.sem_flg = 0;



semop(semId,&smop,1);
smop.sem_num = -1;
smop.sem_op = -1;
smop.sem_flg = 0;



semop(semId,&smop,1);
puts(pShm+RESP_MSG_START);
}
return 0;
}