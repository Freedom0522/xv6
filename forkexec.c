#include "kernel/types.h"
#include "user/user.h"


int main(){
    int pid,status;
    pid = fork();
    if(pid == 0){
        char *argv[] = {"echo","THIS","IS","ECHO",0};
        exec("echo",argv);
        printf("exec failed!\n");
        exit(1);
    }
    else{
        printf("parent waiting");
        wait(&status);
        printf("the child exited with status %d\n",status);

    }
    exit(0);
}