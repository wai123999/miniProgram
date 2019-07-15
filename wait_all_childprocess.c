#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    pid_t childpid;
    pid_t cpid;
    int status;
    for ( int i = 0; i < 2 ; i++ )
    {
       childpid = fork();
       if ( childpid == 0 ) break;
    }
    if ( childpid == 0 ){
          printf("i am process %ld, my parent is %ld\n",getpid(),getppid());
	  while(1);
    }
    while( cpid = waitpid(-1,&status,0))
    {
        if ( cpid == -1 ) break;
    }
    
    




}
