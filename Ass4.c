#include<stdio.h>
#include<stdlib.h>
#include<utmp.h>
#include<sys/wait.h>
#include<utmpx.h>
void who()
{
        struct utmpx *ut;
        setutxent();
        while((ut=getutxent())!=NULL)
        {
                if(ut->ut_type=USER_PROCESS)
                {
                printf("User is : %s\n",ut->ut_user);
                }
        }
        endutxent();
}

int main()
{
        int pid,gid;
        pid = fork();
        if(pid == -1)
        {
                exit(1);
        }
         else if(pid == 0)
        {
                gid = fork();
                if(gid == -1)
                {
                        exit(1);
                }

                else if(gid == 0)
                {

                        printf("GRAND CHILD: ");
                        who();
                        exit(0);
                }
                else
                {
                        printf("CHILD: I am child and I will wait for Grand Child Process\n");
                        wait(NULL);
                        exit(0);
                }
        }

        else
        {
                printf("PARENT: I am parent and I will wait for all my Child and Grand child Processes!!\n");
                wait(NULL);
        }

return 0;
}