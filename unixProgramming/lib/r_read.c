#include <errno.h>
#include <unistd.h>

//ssize_t r signer interger
//read not interrupt
//如果return -1 代表有問題
ssize_t r_read(int fd,char *buf,size_t size){
   
   ssize_t readbytes; 
   while ( readbytes = read(fd,buf,size), readbytes == -1 && errno == EINTR ){}
   return readbytes; 
}
