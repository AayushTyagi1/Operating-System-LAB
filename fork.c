#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid;
	pid=fork();
	if(pid<0)
	printf("ERROR");
	else if(pid == 0)
	printf("In Children\n");
	else
	printf("IN parent\n");
	return 0;
}
