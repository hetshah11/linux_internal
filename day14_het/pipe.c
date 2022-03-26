#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
    {
        int fds[2];
        int res,i;
        char *buf1="aaaaaaaaaaaaaaaaa";
        char *buf="bbbbbbbbbbbbbbbbb";
        char buf2[40];

        res=pipe(fds);

        if(res==-1)
            {
                perror("pipe");
                exit(1);
            }
        int k=write(fds[1],buf1,20);
        int j=write(fds[1],buf,20);
        printf("%d\n",k);
        printf("%d\n",j);

        read(fds[0],buf2,k+j);

        for(i=0;i<k+j;i++)
            {
                printf("%c",buf2[i]);
            }
            printf("\n");

            return 0;


    }