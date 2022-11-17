#include <stdio.h>
#include <unistd.h>
//#include <pthread.h>
#include <sys/wait.h>


//void *worker(void *args);


int main()
{
    pid_t parent,a,b;

    parent = getpid();
    fork();
    a = getpid();
    if( a!=parent )
    {
        fork();
        b = getpid();
        if( a==b )
            printf("I am the : %d ppid: %d\n",a,getppid());
        else
            printf("I am the grand: %d ppid: %d\n",b,getppid());
    }
    else
    {
        printf("I am the parent: %d\n",parent);
    }
    
    return(0);
}



/*void *worker(void *args){
    while (1) 
        printf("I am alive\n");
}*/

