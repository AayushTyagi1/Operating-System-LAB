#include<stdio.h>	
#include<unistd.h>	
int main()	
{	
	int pid = fork();	
	if(pid<0)	
	printf("Child process creation unsuccessful!\n");	
	else if(pid == 0)	
	{
		printf("Process id of child: %d\n",getpid());
		printf("Process id of its parent: %d\n",getppid());
	}
	else	
	{
		printf("My ID: %d\n",getpid());
		printf("Process id of parent: %d\n",getppid());
		printf("Process id of its child: %d\n",pid);
	}
	return 0;	
}
