#include <stdio.h>
#define ADD 0
#define MIN 1
// ADD, MIN -> 메크로, 1, 0 -> 메크로 몸체 // 선행처리 명령문

int main(void){
    int num1, num2;
    scanf("%d %d", &num1, &num2);

#if ADD
    printf("%d + %d = %d", num1, num2, num1+num2);
#endif

#if MIN
    printf("%d - %d = %d", num1, num2, num1-num2);
#endif

    return 0;
}