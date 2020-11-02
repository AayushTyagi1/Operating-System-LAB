#include<dirent.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
    int pid_1,pid_2;

    pid_1 = fork();

    if(pid_1 < 0)
    {
         printf("\nError\n");
    }

    else if(pid_1 == 0)
    {
         printf("\nI am first Child");
         printf("\nMy ID is : %d\n",getpid());
         printf("My PARENT PROCESS ID is : %d\n",getppid());
         DIR *d;
         struct dirent *dir;
         d = opendir(".");
         if (d)
         {
             while ((dir = readdir(d)) != NULL)
             {
                  printf("%s\n", dir->d_name);
             }
              closedir(d);
         }
    }

    else
    {
        sleep(2);

        pid_2 = fork();

        if(pid_2 < 0)
        {
            printf("\nError, Second child is not created");
        }

        else if(pid_2 == 0)
        {
            sleep(1);
            printf("\nI am Second Child");
            printf("\nMy ID is : %d\n",getpid());
            printf("\nMy PARENT ID is : %d\n",getppid());
        }

        else
        {
             printf("\nI AM PARENT");
             printf("\nMy ID is : %d\n",getpid());
             printf("\nMy CHILD PROCESS ID is : %d\n",pid_2);
        }
     }

     return(0);
}
