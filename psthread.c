#include <stdio.h>
#include <unistd.h>
//#include <pthread.h>



//void *worker(void *args);


int main()
{
    pid_t parent,child,grandchild;

    parent = getpid();
    fork();
    child = getpid();
    if(child == 0){
        fork();
        grandchild = getpid();
        if(grandchild == 0){
            printf("Im in grandchild with Pid: %d and PPid: %d\n",getpid(),getppid());
        }else{
            printf("Im in child with Pid: %d and PPid: %d\n",getpid(),getppid());
        }
    }else{
        int returnStatus;    
        waitpid(grandchild, &returnStatus, 0);
        if(returnStatus == 0 ){
            printf("the grandchild process has terminated normally ...\n");
        }
        else if(returnStatus == 1 ){
            printf("the grandchild process has terminated with an error ! \n");
        }
        printf("Im in parent with Pid: %d\n",getpid());
    }
    return(0);
}


/*void *worker(void *args){
    while (1) 
        printf("I am alive\n");
}*/
