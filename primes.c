// #include "kernel/types.h"
// #include "user/user.h"

// #define READ_END 0
// #define WRITE_END 1

// void do_prime_sieve(int oldChan[2]) {
//   int p, n;
//   int newChan[2];

//   /* `oldChan` is inhedited from its parent, just read from the pipe. */
//   close(oldChan[WRITE_END]);
//   /* nothing in the pipe */
//   if (read(oldChan[READ_END], &p, 4) == 0) {
//     close(oldChan[READ_END]);
//     return;
//   }
//   printf("prime %d\n", p);

//   if (pipe(newChan) < 0) {
//     fprintf(2, "pipe failed\n");
//     exit(1);
//   }

//   /* create a new child as its right neighbour */
//   if (fork() == 0) {
//     // child
//     do_prime_sieve(newChan);
//   } else {
//     // parent
//     close(newChan[READ_END]);
//     while (read(oldChan[READ_END], &n, 4) != 0) {
//       if (n % p != 0) {
//         write(newChan[WRITE_END], &n, 4);
//       }
//     }
//     /* close all holding pipes after use */
//     close(oldChan[READ_END]);
//     close(newChan[WRITE_END]);
//   }
// }

//  int main(int argc, char *argv[]) {
//   int oldChan[2];
//   if (pipe(oldChan) < 0) {
//     fprintf(2, "pipe failed\n");
//     exit(1);
//   }

//   if (fork() == 0) {
//     // child
//     do_prime_sieve(oldChan);
//   } else {
//     // parenet
//     close(oldChan[READ_END]);
//     for (int i = 2; i <= 35; ++i) {
//       write(oldChan[WRITE_END], &i, 4);
//     }
//     close(oldChan[WRITE_END]);
//   }

//   wait((void *)0);
//   exit(0);
// }


#include"kernel/types.h"
#include"user/user.h"
//#include"user

 int main(){
   int fd[2];
   int f[2];
   if(pipe(fd) == -1){
     printf("First pipe occured error");
     exit(1);
   } //判断管道是否创建成功
   if(pipe(f) == -1){
     printf("Second pipe occured error");
     exit(1);
   }
   int id1;
   id1 = fork();
//   // tnt is_Prime;
  
  
   for(int i = 2;i <= 35;++i){
//     //int is_Prime = 1;
     if(id1 == 0){
//     //printf("*");
     if((read(fd[0],&i,sizeof(int))) == -1){
       printf("Error");
       exit(1);
     }
    int is_Prime = 1;
//   //printf("%d",i);
    for(int j = 2;j<i;++j){
     if(i%j==0){
       is_Prime = 0;
       break;
     }
    }
//   //  if(is_Prime){
//   //   printf("%d",i);
//   //  }


    if(is_Prime){
      int c_id = fork();
      if(c_id == -1){
       printf("child2 processing error");
       exit(-1);
      }
      if(c_id == 0){
          if(read(f[0],&i,sizeof(int)) == -1){
           printf("Reading Error");
           exit(1);
          }
          printf("prime:%d\n",i);
//          //close(f[0]);
//          //kill(c_id);
      }
      else{
       if((write(f[1],&i,sizeof(int)))== -1){
       printf("Writting Error");
       exit(-1);
      }
//     // close(f[1]);
    exit(0);
    }
   }
  }
  else{
        if((write(fd[1],&i,sizeof(int))) == -1){
        printf("Data writing process wrong");
        exit(1);
    } //将数据挨个写入管道
//     // int status;
//     // wait(&status);
//     //close(fd[1]);
//     //close(fd[1]);
   }
 }


// // for(int i = 2;i<=35;++i){
// //   int is_Prime = 1;
// //   for(int j = 2;j < i;++j){
// //     if(i % j == 0){
// //       is_Prime = 0;
// //       break;
// //     }
// //   }
// //   if(is_Prime){

// //   }
// // }


//     // for(int j = 2;j < i;++j){
//     //    //
//     //    if(i % j == 0){
//     //     //printf("%d",j);
//     //     is_Prime = 0;
//     //     break;
//     //    }//判断是否为质数
//     // }
//     // if(is_Prime){
//     //    printf("%d\n",i);
//     //    int fd2[2];
//     //     if(pipe(fd2) == -1){
//     //     printf("First pipe occured error");
//     //      exit(1);
//     //     }//创建另一个管道
//     //     int id1 = fork(); //child1创建子进程
//     //     if(id1 == 0){
//     //     //printf("processing\n");
//     //     //close(fd[0]);
//     //     if((read(fd[0],&i,sizeof(int))) == -1){
//     //       printf("Data reading process wrong");
//     //        exit(1);
//     //       }//子进程读取管道
//     //     close(fd[0]);
//     //    //关闭读端
//     //     if((write(fd2[1],&i,sizeof(int))) == -1){
//     //     printf("Data writing process wrong");
//     //     exit(1);
//     //     }//子进程写入另一个管道
//     //     close(fd2[1]);//关闭写端
//     //     exit(0);//结束子进程
//     //     //kill(getpid());
//     //   }
//     //   else{ //parent
//     //     int id2 = fork(); //child2 创建第二个子进程
//     //     if(id2 == 0){
//     //       //close(fd2[1]);
//     //       if((read(fd2[0],&i,sizeof(int))) == -1){
//     //       printf("Data reading process wrong");
//     //       exit(1);//读管道数据
//     //       }
//     //       printf("%d",i);//打印
//     //       close(fd2[0]);
//     //       kill(id2);
//     //       //exit(0);
//     //     }
//     //     else{
//     //       int status;
//     //       wait(&status);//等待子进程完毕
//     //       close(fd[0]);
//     //       close(fd[1]);
//     //       //exit(0);
//     //     }
//     //   }
//     //   //printf("%d\n",i);
//     // }
      
   }   
