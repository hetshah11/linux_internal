#include<stdio.h>
#include<string.h>

void my_mem_copy(char *src,char *dest,int count)
            {       int i;
                    //strcpy(dest,src,n);

                    for(i=0;i<count;i++)
                        {
                            *dest=*src;
                            dest++;
                            src++;
                        }
                    printf("After memmove dest = %s, src= %s\n",dest,src);
            }


int main()
	{
		char dest[] ="het";
		const char src[] = "shah";
        

		printf("Before memmove dest = %s, src= %s\n",dest,src);
		my_mem_copy(src,dest,3);
		

		return 0; 
	}