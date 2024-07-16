Ass1 : Write a C program which will take the Process ID and signal ID as input to demonstrate the use of kill( ) system call.

Ass2 : Write a C program to create a child process using the system call fork( ). From the child process, display the PID and PPID and then call again the fork( ) to create a grandchild
and engage him to display your roll no. From parent display the PID and PPID of all the processes and display the count of total no. of child processes created also the number 
of grandchild processes created. Demonstrate the use of exit(0) and exit(1).

Ass3 : Write a C program using signal() system call to handle the reception of SIGINT signal which allows to execute a designated (user) function. Here the function is
responsible for creating a child process by using fork() system call and then you have to display the PROCESS ID and PARENT PROCESS ID from the parent process as well as 
from the child process.

Ass4 : Write a C program like the assignment 1(a). But here use the system call wait() system to synchronize the execution of parent program in your program until child process
finishes. Now write a function to print to nfind out who is logging in the local machine that is partially equivalent to the cmd "w" or "who" and engage the grandchild to print the
output into the stdout.
