#include <stdio.h>
#include <stdlib.h>

int globalVar; // 초기화 되지 않은 전역변수 -> BSS(Block Started by Symbol) 영역에 저장
int globalVarTwo = 10; // 초기화 된 전역변수 -> Data 영역에 저장

const int constVar = 100; // 상수 -> Const 영역에 저장 

int main(){

    int localVar = 20; // 지역변수 -> stack 영역에 저장

    int* dynamicVal = (int*)malloc(sizeof(int)); // 동적 메모리 할당 함수 -> heap 영역에 저장

    printf("BBS 주소 :\t%x\n", &globalVar);
    printf("Data 주소 :\t%x\n", &globalVarTwo);
    printf("Const 주소 :\t%x\n", &constVar);
    printf("Stack 주소:\t%x\n", &localVar);
    printf("Heap 주소:\t%x\n", &dynamicVal);

    return 0;
}