#include<stdio.h>
#include<string.h>

int main()
	{
		const char str[]="linuxkernel.com";
		const char ch ='.';
		char *ret,*ret1;

		printf("string before set/initialization is %s\n",str);
		
		ret=memchr(str,ch,strlen(str));
		
		
		
		printf("string after %c is %s\n",ch,(ret+1));

		return 0;
	}
