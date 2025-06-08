#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<error.h>

int main(){
    int fd[2];//fd[0]-read fd[1]-write
    if(pipe(fd) == -1){
        printf("An error occurred with opening the pipe\n");
        return 1;
    }
    int id = fork();
    if(id == -1){
        printf("An error occurred with opening the pipe\n");
        return 2;
    }
    if(id == 0){
        int x;
        printf("Input an number ");
        scanf("%d",&x);
        close(fd[0]);
        if((write(fd[1],&x,sizeof(int))) == -1){
            printf("An error occurred with opening the pipe\n");
            return 2;
        }
        close(fd[1]);
    }
    else{
        int y;
        close(fd[1]);
        if((read(fd[0],&y,sizeof(y)) == -1)){
            printf("An error occurred with opening the pipe\n");
            return 2;
        }
        printf("Get children number %d",y);
        close(fd[0]);
    }
}
