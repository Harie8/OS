#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<signal.h>
int main(void)
{
        void sigint_handler(int);
        char s[200];
        if(signal(SIGINT, sigint_handler)==SIG_ERR)
                {
                        perror("signal");
                        exit(1);
                }
                printf("Enter Your Roll No. : \n");
                if(gets(s) == NULL)
                {
                        perror("gets");
                        exit(1);
                }
                else
                {
                        printf("Your Roll No is : %s\n",s);
                }
        return 0;
}
void sigint_handler(int sig)
{
        pid_t pid;
        int a;
        pid = fork();
        if(pid == 0)
        {
                printf("CHILD: PID and PPID is : %d,%d\n",getpid(),getppid());
                a = getpid();
                exit(a);
        }
        else
        {
                printf("PARENT: Lets wait for child execution!\n");
                wait(&a);
                printf("PARENT: Parent Resume!!\n");
                printf("PARENT: PID and CID is : %d,%d\n",getpid(),pid);
        }

}