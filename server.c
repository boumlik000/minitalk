#include<unistd.h>
#include<stdio.h>
#include <signal.h>


// void handler(int signum)
// {
//     if (signum == SIGUSR1)
//     {
//         printf("boumlik\n");
//     }
// }


int main()
{
    // printf("hello words");
    int pid;

    pid = getpid();
    printf("PID: %d\n", pid);
    // signal(SIGUSR1, &handler);
    while(1)
    {
        
    }
}