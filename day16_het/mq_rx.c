#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

struct msgbuf
{
    long mtype;
    char data[512];
};

int main(int argc, char *argv[])
{
    int id;
    struct msgbuf v;
    struct msqid_ds buf;
    // if (argc != 3)
    // {
    //     printf("Usage: ./mq_rx type\n");
    //     printf("Example: mq_rx 5\n");
    //     return 0;
    // }

    id = msgget(55, IPC_CREAT | 0644);

    // msgctl()
    if (id < 0)
    {
        perror("msgget");
        return 0;
    }

    msgrcv(id, &v, sizeof(v),v.mtype, 0);
    printf("Data: %s\n", v.data);

     msgctl(id, IPC_RMID, NULL);
    return 0;
}