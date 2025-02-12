#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include "setjmp.h"
jmp_buf buf;
void handler(){
    longjmp(buf, 1);
  
}
char* tfgets(char* s,int size,FILE* stream){
    signal(SIGALRM,handler);
    alarm(5);
    if (!setjmp(buf)) {
        return fgets(s, size, stream);
    }
    else {
    return NULL;
    }
}
int main(){
    char buffer[256];
    char* res=tfgets(buffer, 256, stdin);
    printf("%s",res);
}