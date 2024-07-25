#include <stdio.h>
#define NUM 10

int main(){
    #if NUM == 5
        puts("NUM = 5");
    #elif NUM == 7
        puts("NUM = 7");
    #else   
        puts("아무것도 아님");
    #endif

    return 0;
}