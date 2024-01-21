#include <stdio.h>
#include<windows.h>
using namespace std;       
int main(){
    int tc=1;
    int h=0,m=0,s=0;
    while(1){
        printf("%2d:%2d:%2d\r",h,m,s);
        Sleep(1000);
        s++;
        if(s==60){
            s=0;
            m++;
            if(m==60){
                m=0;
                h++;
                if(h==24){
                    h=0;
                }
            }
        }
    }
    return 0;
}