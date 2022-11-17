#include <stdio.h>
#include <unistd.h>
//#include <pthread.h>



//void *worker(void *args);


int main()
{
    pid_t parent,a,b;

    parent = getpid();
    fork();
    a = getpid();
    if( a==parent )
    {
        printf("I am the parent: %d\n",parent);
    }
    else
    {
        fork();
        b = getpid();
        if( a==b )
            printf("I am the child: %d ppid: %d\n",a,getppid());
        else
            printf("I am the grandchild: %d ppid: %d\n",b,getppid());
    }

    return(0);
}


/*void *worker(void *args){
    while (1) 
        printf("I am alive\n");
}*/
