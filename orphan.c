#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	
	if(pid<0)
		printf("FORKED FAIL");
	else if(pid==0)
	{
		sleep(6);
		printf("\n I am child. PID: %d and PPID %d",getpid(),getppid());
		}
	else
	{
		printf("I am parent Child PID: %d\nand my PID:%d",pid,getpid());
	}
	printf("\nTerminating PID =%d\n",getpid());
}
