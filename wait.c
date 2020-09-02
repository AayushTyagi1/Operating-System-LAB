#include<stdio.h>	
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>	
int main()	
{	
	int pid = fork();	
	if(pid<0)	
	printf("Child process creation unsuccessful!\n");	
	else if(pid == 0){	
	printf("Child process created\n");	
	exit(0);
	}
	else	
	{
		wait(0);
		printf("it is parent process");
	}
	return 0;	
}
