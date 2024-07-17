#include <stdio.h>

void swap(int *a, int *b){
	int temp; // 임시로 a 나 b 값을 저장할 temp 변수
	temp = *a;
	*a = *b;
	*b = temp;
	
}


int main(){
	
	int a, b;
	printf("Type A, B : ");
	scanf("%d %d", &a, &b);
	
	printf("Before Swap A, B : %d %d\n", a, b);
	
	printf("Address of A : %x, B : %x\n", &a, &b);
	
	swap(&a, &b);
	printf("After Swap A , B : %d , %d", a, b);
	
	return 0;
}