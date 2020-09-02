#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	printf("PROCESS FAILED");
	else if(pid >0)
	{
		sleep(50);
	}
	else
	{
	exit(0);
	}
}
