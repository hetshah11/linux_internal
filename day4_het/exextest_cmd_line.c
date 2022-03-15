#include<stdio.h>

int main(int argc,char *argv[])
	{
		int i;
		printf("\nFile name : %s\n",argv[0]);
		printf("Total  umber of arguments: %d\n",argc);
		printf("\nArguments passed: ");
		
		for(i=1;i<argc;i++)
			{
				printf("%s ",argv[i]);
			}
		printf("\n");
	}
