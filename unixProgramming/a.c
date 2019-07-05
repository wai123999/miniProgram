#include <stdio.h>
#include <unistd.h>

int main(void){
    int x = 0;;
    pid_t mypid = getpid();
    pid_t childpid;
    printf("i am %ld\n",(long)mypid);
    childpid = fork();
    if ( childpid == 0 ){ 
     printf("i am child process %ld and my parent is %ld...%ld....\n",(long)getpid(),(long)getppid(),(long)mypid);
   }
   else { 
	x = 1;
     printf("i am process %ld and my x is %ld....\n",(long)getpid(),(long)mypid);
   }

}
