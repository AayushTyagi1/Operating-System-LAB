#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("World\n");
	fork();
	printf("Hello\n");
	fork();
	printf("How\n");
	fork();
	printf("ru\n");
}
