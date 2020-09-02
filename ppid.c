#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid;
	pid=fork();
	if(pid == 0)
	{
		printf("Parent process id of current process: %d\n",getpid());
		printf("Child process with parent id: %d\n",getppid());
	}
}
