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

int main(){
    int fd[2];
    if(pipe(fd) == -1){
        printf("First prime error");
        exit(1); // creat first prime 
    }
    int id = fork();//child1
    for(int i = 2;i <= 35;++i ){
        if(id == 0){
        c_id = fork(); //create child2
        if(c_id == 0){
            int tmp;
            read(fd[0],&tmp,sizeof(int));
            //close(fd[0]);
            int f[2];
            if(pipe(f) == -1){
                printf("Second pipe error");
            }
            int is_Prime = 1;
            for(int j = 0; j< tmp;++j){
                if(tmp % j == 0){
                    is_Prime = 0;
                    break;
                }
            }
            if(is_Prime){
                write(f[1],&tmp,sizeof(int));
            }

        }
        else{
            int c_tmp;
            close(f[1]);
            read(f[0],&c_tmp;sizeof(int));
            printf("primes:%d",&c_tmp);

        }
    }
        else{
            if((write(fd[1],&i,sizoef(int)))== -1){
                printf("Wrinting error");
            }
        }
       }    
    }
    