#include <iostream>
#include <cstring>
using namespace std;


bool lookAdjHaveSoldier(string s,char* pos,int index,int len);
bool isValid(string s,char* pos,int index);

int main(int argc,char*argv[]){

    //string s = "..#.#.##....##";
    string s = "####";
    int useSoldier = 0;
    int maxSoldier = s.length();
    char *pos = new char[maxSoldier];
    
    //記錄士兵的位置的陣列..
    for ( int i = 0; i < maxSoldier ; i++)
         pos[i] = '1';
    
    //把士兵拿走後看看可不可以
    for ( int i = 0 ; i < maxSoldier ; i++){
         pos[i] = '0';
         if ( !isValid(s,pos,i)) //唔得就變回１
            pos[i] = '1';
         /*
         for ( int i = 0; i < maxSoldier ; i++)
         {
            cout<<pos[i];
         }
         cout<<endl;
         */
    }
    //cout<<s<<endl;
    for ( int i = 0; i < maxSoldier ; i++)
    {
         if ( pos[i] == '1') useSoldier++;
    //     cout<<pos[i];
    }
    //cout<<endl;
    //cout<<"It need Soldier "<<useSoldier<<endl;
    cout << useSoldier<<endl;
    
}
bool lookAdjHaveSoldier(string s,char* pos,int index,int len)
{
    //沒有考慮頭和尾情況
    if ( s[index] == '.'){
        if ((s[index-1] == '.') && (pos[index-1] == '0'))  
            return false;
    }
    else if ( s[index] == '#' ){
        if ( (s[index -1] == '.' ) && ( pos[index-1] =='0') && pos[index-2] != '1')
           return false;
    }
    return true;
}
bool isValid(string s,char* pos,int index){
     //如果沒人駐守
     if ( !lookAdjHaveSoldier(s,pos,index,s.length()))
                 return false;
     return true; 
}
