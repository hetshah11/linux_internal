#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/msg.h>

// Sender

typedef struct
{
    long msgtype;
    char buffer[100];
} msg;

int main()
{

    int qid;
    int i;
    msg m1, m2;
    qid = msgget(32, IPC_CREAT | 0644);

    m1.msgtype = 10;

    for (int i = 0; i < 100; i++)
    {
        m1.buffer[i] = 'a';
    }
        m2.msgtype = 20;
    for (int i = 0; i < 100; i++)
    {
        m2.buffer[i] = 'b';
    }

    i = msgsnd(qid, &m1, sizeof(msg), 0);
    printf("Return value of msgsnd of As = %d\n", i);
    i = msgsnd(qid, &m2, sizeof(msg), 0);
    printf("Return value of msgsnd of Bs= %d\n", i);
}