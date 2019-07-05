#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 
  
int main() 
{ 
    pid_t cpid; 
    pid_t mpid_array[2];
    pid_t mpid;
    for ( int i = 0 ; i < 2 ; i++ )
    {
        mpid = fork();  
	mpid_array[i] = mpid;
	if ( mpid == 0 )
	{
		break;
	}
    }
    while ( mpid == 0 ){}
    int status;
 //   for ( int i = 0 ; i < 2 ; i++ ){ 
   // 	cpid = waitpid(mpid_array[i],&status,0); /* reaping parent */
    //}
    while (cpid = waitpid(-1,&status,0)) /* reaping parent */
    {
       if ( cpid == -1) {break;}
    }
    printf("The cpid is process = %d\n", cpid); 
  

    return 0; 
} 
