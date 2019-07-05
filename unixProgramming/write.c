#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    int file = open("b.c",O_CREAT);
    printf("%d\n",errno);


}
