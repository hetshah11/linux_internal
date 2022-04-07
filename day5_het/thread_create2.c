#include<stdio.h>
#include<pthread.h>

struct char_print_params
    {
        char character;
        int count;
    };

void *char_print(void *parameters)
    {
        struct char_print_params *p = (struct char_print_params *)parameters;
        int i;
        printf("structure char data= %c and count=%d\n",p->character,p->count);
        return NULL;
    }

int main()
    {
        pthread_t thread1_id;
        pthread_t thread2_id;

        struct char_print_params thread1_args;
        struct char_print_params thread2_args;

        thread1_args.character='x';
        thread1_args.count=20;

        pthread_create(&thread1_id,NULL,&char_print,&thread1_args);
        thread2_args.character='z';
        thread2_args.count=200;

        pthread_create(&thread2_id,NULL,&char_print,&thread2_args);

        pthread_join(thread1_id,NULL);
        pthread_join(thread2_id,NULL);

        return 0;

    }