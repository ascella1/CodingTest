#include <stdio.h>

int main(void){
    int a = 10;
    int *p = &a; // 포인터
    int **p2 = &p;//이중 포인터

    printf("p = %d, &p = %d, *p = %d\n", p, &p, *p);
    printf("p2 = %d, &p2 = %d, *p2 = %d, **p2 = %d", p2, &p2, *p2, **p2);

    return 0;
}