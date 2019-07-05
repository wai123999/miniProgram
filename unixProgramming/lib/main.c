#include <stdio.h>
#include <fcntl.h>    //open
#include <sys/stat.h> //open
#include <unistd.h>

#define BLOCK_SIZE 256
//#include "r_read.c"
int main(){
  char buf[BLOCK_SIZE]; 
  ssize_t readbytes = 0;
  int totalbytes = 0;
  while ( readbytes = r_read(STDIN_FILENO,buf,BLOCK_SIZE)){
      if ( readbytes == 0 ){ printf("Read The file success!\n");break;}
      else if ( readbytes == -1 ) break;
      else //printf("The first bytes is %ld\n",readbytes);
      totalbytes += readbytes;
  }
  printf("The totalbytes is %ld\n",totalbytes);
  return 0;
}
