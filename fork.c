#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid = fork();
	if(pid<0)
	printf("Child process creation unsuccessful!\n");
	else if(pid == 0)
	printf("Child process created\n");
	else
	printf("It is the parent process\n");
	return 0;
}
