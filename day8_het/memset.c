#include<stdio.h>
#include<string.h>

int main()
	{
		const char str[]="linuxkernel.com";
		const char ch ='#';

		printf("string before set/initialization is %s\n",str);
		
		memset(str,ch,strlen(str));
		//memset(str,ch)
		
		printf("string after set is %s\n",str);

		return 0;
	}
