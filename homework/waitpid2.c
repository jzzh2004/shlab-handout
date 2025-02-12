#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#define N 2
int main(){
    int status,i;
    pid_t pid;
    
    for (i=0; i<2; i++) {
        if ((pid=fork())==0) {
            int*p=0; 
            *p=0;
            return 0;
        }
    }
    while((pid=waitpid(-1, &status, 0))>0){
        printf("child %d terminated by signal %d : SEgmentation fault\n",pid,WTERMSIG(status));
    }
}