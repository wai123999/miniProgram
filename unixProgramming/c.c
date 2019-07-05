#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc,char *argv[]){
    pid_t childpid;
    childpid = fork();
    char buf[256];
    char *d = getwd(buf);    
    printf("%s\n",d);
    if ( childpid == 0 ){
       //child
       execvp(argv[1],&argv[1]);
    }
    return 0;
}
