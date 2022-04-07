#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int pipe_fds[2];

int main()
{
    pid_t pid;
    int res = pipe(pipe_fds);

    if (res == 0)
        printf("Pipe created succesfully\n");

    pid = fork();

    if (pid != 0)
    {
        int w;
        char buf_send[100];

        printf("Enter data to be sent\n");
        gets(buf_send);
        w = write(pipe_fds[1], buf_send, 100);

        printf("Data sent to pipe............%s\n\n", buf_send);
        sleep(1);

        // while(1)
        //     {

        //     }
        wait();
        return 0;
    }
    else
    {
        int r;
        char buf_rcv[100];
        int w;

        r = read(pipe_fds[0], buf_rcv, 100);

        for (int i = 0; i < strlen(buf_rcv) - 1; i++)
        {
            if (buf_rcv[i] >= 'A' && buf_rcv[i] <= 'Z')
                buf_rcv[i] += 32;

            else if (buf_rcv[i] >= 'a' && buf_rcv[i] <= 'z')
                buf_rcv[i] -= 32;
        }

        printf("Data read is: %s\n\n", buf_rcv);

        printf("\nHere we can see that, read data is in toggle form\n\n");

        printf("Data flow order from WRITE end to READ end:\n\n");
        printf("Every Letter written at write end is toggled at read end\n");
        // sleep(1);

        // r=read(pipe_fds[0],buffer,100);

        exit(0);
    }
}