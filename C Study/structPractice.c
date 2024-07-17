#include <stdio.h>
#include <string.h>

struct Student{
	int number;
	char name[10];
	double grade;
			
};

int main(){
	struct Student s;
	
	printf("Student No : ");
	scanf("%d", &s.number);
	printf("Student Name : ");
	scanf("%s", s.name); // 문자형인 경우는 & 로 주소를 가져오지 않음
	printf("Student Grade : ");
	scanf("%lf", &s.grade);
	
	printf("sNo : %d, sNa : %s, sGra : %.2f", s.number, s.name, s.grade);
	
	return 0;
}