#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void sig_handler(int sig);
int main()
{
        printf("Going to print infinite loop!!\n");
        int i=1;
        signal(SIGTERM, sig_handler);
        signal(SIGKILL, sig_handler);

        while(i>0)

{
                printf("%d\n",i);
                i++;
                sleep(1);
        }
   return 0;
}
void sig_handler(int sig)
{
        if(sig == SIGTERM)
        {
                printf("SIGTERM is called!\n");
                printf("Signal ID is : %d\n",sig);
        }
        if(sig == SIGKILL)
        {
                printf("SIGKILL is called!\n");
                printf("signal ID is : %d\n",sig);
        }
}
