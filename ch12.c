#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
	pid_t pid1,pid2,status;
	pid1=fork(); //first child
	if(pid1 > 0)
	{
	    pid2=fork(); // second child
	}
	wait(&status);
	if(pid1 > 0 && pid2 >0)
	{
		printf("PARENT : %d \n",getpid());
	}
	if(pid1 == 0 && pid2 >0)
	{
		printf("FIRST CHILD : %d \n",getpid());
		exit(0);
	}
	else if(pid2 == 0 && pid1 >0)
	{
		sleep(10);
		printf("SECOND CHILD : %d \n",getpid());
	}
	
	
}
