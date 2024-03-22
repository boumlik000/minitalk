#include<unistd.h>
#include<stdio.h>
#include <signal.h>
#include <stdlib.h>


int main(int ac, char **av)
{
    // if (ac == 3)
    // {
        kill(atoi(av[1]), SIGUSR1);
    // }
}