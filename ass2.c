Better spam filters … Now Drive automatically moves suspicious files shared with you to spam. You can still report spam yourself.Learn more
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
        int pid,cid,gid,g;
        int c1=0;
        int c2=0;
        pid = fork();
        if(pid == -1)
        {
                exit(1);
        }
        else if(pid == 0)
        {
                c1++;
                gid = fork();
                if(gid == -1)
                {
                        exit(1);
                }

                else if(gid == 0)
                {
                        c2++;
                        FILE *fptr;
                        fptr = fopen("./gid.txt","w");
                        int g = getpid();
                        fprintf(fptr,"%d",g);
                        fptr=fopen("./c2.txt","w");
                        fprintf(fptr,"%d",c2);
                        printf("GRAND CHILD: PID and PPID is %d,%d\n",g,getppid());
                        printf("GRAND CHILD: Hii Harie Your Roll Number is : CSM22043\n\n");
                        exit(g);
                }
                else
                {
                        printf("CHILD: I am child and I will for Grand Child Process\n\n");
                        wait(&g);
                        FILE *fp;
                        fp=fopen("./c1.txt","w");
                        fprintf(fp,"%d",c1);
                        printf("CHILD: Child Resume!!\n");
                        printf("CHILD: PID and PPID is : %d,%d\n\n",getpid(),getppid());
                        int c;
                        c=WIFEXITED(g);
                        exit(c);
                }
        }
        else
        {
                printf("PARENT: I am Parent and I will wait for my Child and Grand Child Processes!!\n\n");
                int a,c;
                a=wait(&c);
                FILE *fptr,*fp;
                fptr = fopen("./gid.txt","rb");
                fscanf(fptr,"%d", &g);
                printf("PARENT: Parent Resume!!\n");
                printf("PARENT: PID, CID and GID is : %d,%d,%d\n\n",getpid(),a,g);
                fclose(fptr);

                fptr=fopen("./c1.txt","rb");
                fscanf(fptr,"%d",&c1);
                printf("PARENT: Number of Child Process is : %d\n",c1);
                fclose(fptr);

                fptr=fopen("./c2.txt","rb");
                fscanf(fptr,"%d",&c2);
                printf("PARENT: Number of Grand Child Process is : %d\n",c2);
                fclose(fptr);


        }
return 0;
}