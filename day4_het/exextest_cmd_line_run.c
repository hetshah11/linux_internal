#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
	{
		pritnf("can you see me [ONE]\n");
		
		execl("/home/het/Desktop/linux_internal/day4_het/exextest_cmd_line.c","./exectest","linux","programming",NULL);
		return 0;
	}
