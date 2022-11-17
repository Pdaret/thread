#include <stdio.h>
#include <unistd.h>
//#include <pthread.h>
#include <sys/wait.h>


//void *worker(void *args);


int main(){
    int child,grandchild;
    child=fork();
    if(child==0){
        grandchild = fork();
        if(grandchild == 0){
            printf("GRANDCHILD pid=%d   PARETN pid=%d\n",getpid(),getppid());
        }
        else if(grandchild>0){
        printf("CHILD pid=%d   PARETN pid=%d\n",getpid(),getppid());
        }
    }
    else if(child>0){
        int returnStatus;    
        waitpid(grandchild, &returnStatus, 0);

        if (returnStatus == 0)    
        {
            printf("The child process terminated normally.");    
        }

        if (returnStatus == 1)      
        {
            printf("The child process terminated with an error!.");    
        }
        printf("PARENT VALUE=%d\n",getpid());
    }
    return(0);
}



/*void *worker(void *args){
    while (1) 
        printf("I am alive\n");
}*/
    /* pid_t parent,a,b;

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
            printf("I am the : %d ppid: %d\n",a,getppid());
        else
            printf("I am the grand: %d ppid: %d\n",b,getppid());
    } */