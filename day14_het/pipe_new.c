#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
    {
        int p[2];

        pipe(p);
        printf("Read one end pipe=%d\twrite end of pipe=%d\n",p[0],p[1]);

        if(fork())
            {
                char s[20];
                printf("In parent Enter Data..\n");
                scanf("%s",s);
                write(p[1],s,strlen(s)+1);
                // wait(0);
            }
        else    
            {
                char buf[20];
                printf("In child..\n");
                read(p[0],buf,sizeof(buf));
                printf("child process printing..Data of the parent process..%s\n",buf);
                // return 0;
                exit(0);
            }

            return 0;
    }