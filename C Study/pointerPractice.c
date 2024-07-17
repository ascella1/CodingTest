#include <stdio.h>

int main(){

    int arr[5] = {10,20,30,40,50};
    int *p = arr; // arr가 있는 주소값에 접근한 후 배열의 첫번째 값을 가져오는 *p 변수 
    // arr 의 첫번째 요소(10)의 주소를 p 에 저장한 것.
    //즉 p = &arr[0] 과 동일하다. 

    printf("p : %d\n", p); //6422000
    printf("p + 1 : %d\n", p + 1);//6422004
    printf("*p + 1 : %d\n", *p + 1);//11
    printf("*(p + 1) : %d\n", *(p + 1));//20
    //p + 1 -> 6422004 p는 int형 포인터이기 때문에 p + 1은 p의 주소에서 
    //4바이트(즉, sizeof(int)) 만큼 증가한 주소를 가리킨다. 
    //이 연산은 p가 가리키는 메모리 주소를 int 타입의 크기 단위로 증가시킨다. 
    //*p + 1 -> 11 // p 의 주소에 접근하여 가져온 값 10 에다가 1을 더한 모습이다
    //*(p + 1) -> 20 // arr 를 통해 이미 6422000 ~ 6422016까지 할당받았으므로, 
    //6422004에 저장된 값을 가져오는 것.

    for(int i = 0; i < 5; i++){
        printf("arr[%d] = %d\n", i, *(p + i));
    }

    int test = 10;
    int *q = &test;
    int a = 1;
    printf("q : %d\n", q);
    printf("*q : %d\n", *q);
    printf("q + 1: %d\n", q + a);// 배열이 아니여도 한요소(pointer 변수 q가 char형이므로) 의 크기만큼 이동한다. 
    printf("*q + 1: %d\n", *q + 1);


    /*
    int array[5] = {}; // int 형이 5개 연속으로 이어진 배열이므로 6422016 ~ 6422032 까지 사용함. 

    for(int i = 0; i < 5; i++){
        scanf("%d", &array[i]);
    }
    for(int i = 0; i< 5; i++){
        printf("array[%d]의 주소값 : %d\n", i, &array[i]); 
        printf("array[%d]에 저장된 값 : %d\n", i, array[i]);
    }

    int index, value = 0;
    printf("array 에서 바꾸고 싶은 값의 인덱스 입력 : ");
    scanf("%d", &index);
    printf("바꿀 값 입력 : ");
    scanf("%d", &value);
    
    array[index] = value;
    for(int i = 0; i< 5; i++){
        printf("array[%d]의 주소값 : %d\n", i, &array[i]); 
        printf("array[%d]에 저장된 값 : %d\n", i, array[i]);
    }
    */

    return 0;
}