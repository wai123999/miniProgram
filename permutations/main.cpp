#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
using namespace std;

void printArray(char *, int );
string arrayToString(char *,int );
void printStringArray(string *,int );

int main(int argc , char* argv[]){
     char a[5] = {'a','b','c','d','e'} ;
     char position[5] = {'\0'};
     string permutation[1000] = { "\0"};
     int p = 0;
     srand(time(NULL));
     int k;
     int n = 0;;
     for ( int i = 0 ; i < 1000 ; i++){
         while ( n != 5 ){ 
              k = rand() % 5;
              if ( position[k] == '\0' ){
                   position[k] = a[n];
                   n++;
              }
        }
        //printArray(position,4);
        string s = arrayToString(position,5);
        //if ( s not in pemutation)
        if ( p == 0 ){
            //no permutation 
            permutation[p++] = s;
        }
        else {
            bool flag = true;
            for ( int i = 0; i < p ; i++ )
            {
               if ( permutation[i] == s ) flag = false;
            }
            if ( flag ){
                //no this permutation
                permutation[p++] = s;
            }
        }
        fill_n(position, 5, 0);
        n = 0;
     }
     printStringArray(permutation,p);
     cout<<"The Combination has :"<<p<<endl;
     return 0;
}
void printArray(char* array,int len){
     for ( int i = 0 ; i < len ; i++ )
     {
          if ( i == len - 1 ) cout << array[i] <<endl;
          else cout << array[i] << ' '; 
     }

}
string arrayToString(char *array,int len){
   string s = "";
   for ( int i = 0; i < len ; i++)
       s += array[i];
   return s; 
}

void printStringArray(string *array,int len){
   for ( int i = 0; i < len ; i++)
        cout<<array[i]<<endl;
}
