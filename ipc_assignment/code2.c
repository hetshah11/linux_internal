#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<string.h>

struct msqid_ds msq_structure;

        struct message
            {
                long type;
                char message[70];
            }new_msg[3];

int main()
    {
        

        int msqueue_id;

        msqueue_id=msgget(25,IPC_CREAT | 0644);
            if(msqueue_id<0)
                printf("Error.....\n");

        // struct message new_msg;
        new_msg[0].type=20;
        strcpy(new_msg[0].message,"Het Shah");

        new_msg[1].type=26;
        strcpy(new_msg[1].message,"Raj Patel");

        new_msg[2].type=32;
        strcpy(new_msg[2].message,"Jay Jani");

        // int 
        // printf("%d\n",res);

        // int i=1;
        
        int res;
        for(int i=0;i<3;i++)
            {
                res=msgsnd(msqueue_id,&new_msg[i],sizeof(new_msg[i]),0);

                if(res==0)
                    printf("Message %d sent......%s\n\n",i+1,new_msg[i].message);
                else    
                    printf("Error.......\n");
            }


        msgctl(msqueue_id,IPC_STAT,&msq_structure);

        printf("Number of message in message queue: %d\n\n",msq_structure.msg_qnum);
        printf("No of bytes in message queue: %d\n\n",msq_structure.__msg_cbytes);
        printf("No of Max bytes in message queue:: %d\n\n",msq_structure.msg_qbytes);

        printf("Now we are gping to delete message queue\n\n");

        msgctl(msqueue_id,IPC_RMID,0);

        printf("Message queue deleted succesfully\n");

        return 0;

        




    }