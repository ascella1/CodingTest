#include <stdio.h>
#include <windows.h>

enum States {
    INIT,
    OD,
    FOD,
    PT
};

void initState();
void odState();
void fodState(int *a, int *b);
void ptState();
void swap(int *a, int *b);

int main() {
    enum States currentState = INIT;
    int a = 1000;
    int b = 2000;
    
    int run = 1;

    while(run) {
        switch(currentState) {
            case INIT:
                initState();
                Sleep(2000);
                currentState = OD;
                break;
            case OD:
                odState();
                Sleep(2000);
                currentState = FOD;
                break;
            case FOD:
                fodState(&a, &b);
                Sleep(2000);
                currentState = PT;
                break;
            case PT:
                ptState();
                Sleep(2000); 
                //run = 0; PT //상태 끝난 후 종료하려면 0으로 변경. 
                //currentState = INIT; //무한 반복하려면 현재 상태를 다시 INIT 으로
                break;
            default:
                break;
        }
    }
    return 0;
}

void initState() {
    printf("INIT 상태\n");
}

void odState() {
    printf("OD 상태\n");
}

void fodState(int *a, int *b) {
    printf("FOD 상태\n");
    printf("swap() 함수 실행 전 : %d, %d\n", *a, *b);
    printf("swap() 함수 실행\n");
    swap(&a, &b); // swap 함수에 포인터 전달
    printf("swap() 함수 실행 후 : %d, %d\n", *a, *b);
}

void ptState() {
    printf("PT 상태\n");
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
