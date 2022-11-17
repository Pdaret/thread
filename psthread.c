#include <stdio.h>
#include <unistd.h>
//#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>

//void *worker(void *args);


int main()
{
    pid_t parent,child,grandchild;
    parent = getpid();
    child = fork();
    if (child != 0)
    {
        int returnStatus;
        waitpid(grandchild,&returnStatus,0);
        if (WEXITSTATUS(returnStatus)== 0)
        {
            printf("grandchild exited normally\n");
        }else{
            printf("grandchild exited with status: %d\n",returnStatus);
        }
        printf("im in parent with pid: %d\n",getpid());
        
    }else{
        grandchild = fork();
        if (grandchild == 0)
        {
            printf("im in grandchild with pid: %d  ppid: %d\n",getpid(),getppid());
            exit(0);

        }
        else
        {
            printf("im in child with pid: %d  ppid: %d\n",getpid(),getppid());
            exit(0);
        }
    }
    return(0);
}



/*void *worker(void *args){
    while (1) 
        printf("I am alive\n");
}*/

