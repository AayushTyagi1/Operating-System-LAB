#include<stdio.h>	
#include<unistd.h>	
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#define max 20

int main()	
{
	int pid;
	int a[max],n,sum=0,i,status;
	printf("Enter number of terms in the array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		pid=fork();
		wait(&status);
		if(pid == 0)
		{
			for(i=0;i<n;i++)
			if(a[i]%2==0)
			sum+=a[i];
			printf("sum of even numbers: %d\n",sum);
			exit(0);
		}
			
	        else
	        {
		for(i=0;i<n;i++)
			if(a[i]%2!=0)
			sum+=a[i];
			printf("SUM of ODD nos = %d\n",sum);
	}
	}
}
