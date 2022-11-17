//program written by Sayed Mahdi Rezaei
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>

void *worker(void *args);


int main()
{
    pthread_t tid;
    pthread_attr_t attr;
    pid_t parent,child,grandchild;
    parent = getpid();
    child = fork();
    if (child == 0)
    {

        grandchild = fork();
        if (grandchild == 0)
        {
            printf("im in grandchild with pid: %d  ppid: %d\n",getpid(),getppid());
            exit(0);

        }
        else
        {
            printf("im in child with pid: %d  ppid: %d\n",getpid(),getppid());
            pthread_attr_init(&attr);
            pthread_create(&tid,&attr,worker,NULL);
            pthread_join(tid,NULL);
            pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
            exit(0);
        }
        
    }else{
        int cancelresult;
        int returnStatus;
        waitpid(grandchild,&returnStatus,0);
        if (WEXITSTATUS(returnStatus)== 0)
        {
            printf("grandchild exited normally\n");
            cancelresult = pthread_cancel(tid);
            if(cancelresult==0){
            printf("im in parent with pid: %d and thread canelled successfully...\n",getpid());
            }else{
            printf("im in parent with pid: %d but thread not canelled...\n",getpid());
            }
        }
        else{
            printf("grandchild exited with and error\n");
        }
    }
    return(0);
}



void *worker(void *args){
    int counter =0;
    while (counter !=10){ 
        printf("I am alive\n");
        counter ++;
    }
}

