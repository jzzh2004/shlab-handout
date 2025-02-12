#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int mysystem(char* command){
    pid_t sh_pid;
    int sh_status;
    if((sh_pid=fork())==0){
        execl("/bin/sh", "sh","-c,command",(char*) NULL);
    }
    else{
        if(waitpid(sh_pid,&sh_status,0)==sh_pid){
            if(WIFEXITED(sh_status)){
                return WEXITSTATUS(sh_status);
            }
        }
        else if (WIFSIGNALED(sh_status)) {
            fprintf(stderr,"stoped by signal called %d",WTERMSIG(sh_status));
            return WTERMSIG(sh_status);
        }
    }
    return 1;
}