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

int f[2];
void write_p(int n){
  //int f[2];
  close(f[0]);
  if(fork() == 0){
    for(int i = n;i <= 35;++i){
      if(i%n != 0){
        write(f[1],&i,sizeof(int));
      }
    }
  }
  close(f[1]);
  //exit(0);
  // if(n == 35)return;
  // sieve(n+1,f[1]);
}
int main(){
  int fd[2];
  pipe(fd);
  pipe(f);
  if(fork() == 0){
    // int f[2];
    // pipe(f);
    int n;
    while(read(fd[0],&n,sizeof(int))>0){
         write_p(n);
    };
  }
  
  if(fork() == 0){
    int num;
    close(f[1]);
    while(read(f[0],&num,sizeof(int))>0){
      printf("prime:%d\n",num);
    }
    close(f[0]);
  }
  for(int i = 2;i <= 35;++i){
    write(fd[1],&i,sizeof(int));
  }
  close(fd[1]);
  wait(0);
  wait(0);
  exit(0);
}