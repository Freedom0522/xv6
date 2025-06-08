
#include"kernel/types.h"
#include"user/user.h"

int main(){
  int fd[2];
  if(pipe(fd) == -1){
    printf("1:An error occured");
    return 2;
  }
  int id = fork();
  if(id == -1){
    printf("2:An error occured");
    return 2;
  }
  if(id == 0){
    //close(fd[0]);
    pde_t pid = getpid();
    //printf("pid:%d",pid);
    //pid = getpid();
    if((read(fd[0],&pid,sizeof(pde_t)) == -1)){
      printf("3:An error occured");
      exit(1);
    }
    printf("%d:receive ping\n",getpid());
    close(fd[0]);
    if((write(fd[1],&pid,sizeof(pde_t)) == -1)){
      printf("4:An error occured");
      exit(1);
    }
    close(fd[1]);
    exit(0);
    // close(fd[1]);
    // close(fd[0]); 
  }
  else{
    //int cpid = ;
    pde_t cpid = getpid();
    if((write(fd[1],&cpid,sizeof(pde_t)) == -1)){
      printf("5:An error occured");
      exit(1);
    }
    close(fd[1]);
    //close(f[1]);//close write function
    if((read(fd[0],&cpid,sizeof(pde_t)) == -1)){
      printf("6:An error occured");
      exit(1);
    }
    printf("%d:receive pong\n",getpid());
    close(fd[0]);
    // close(fd[1]);
    // close(fd[0]);
    exit(0);
  }
  
}