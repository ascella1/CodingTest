#include <stdio.h>

// enum 자료형 정의
enum Weekday {
    SUNDAY,    // 0
    MONDAY,    // 1
    TUESDAY,   // 2
    WEDNESDAY, // 3
    THURSDAY,  // 4
    FRIDAY,    // 5
    SATURDAY   // 6
};

int main() {
    enum Weekday today;

    today = TUESDAY;
    
		printf("일주일 중 오늘은 몇번째 ? :  %d\n", today + 1);
    printf("오늘은  ");

    switch(today) {
        case SUNDAY:
            printf("일요일\n");
            break;
        case MONDAY:
            printf("월요일\n");
            break;
        case TUESDAY:
            printf("화요일\n");
            break;
        case WEDNESDAY:
            printf("수요일\n");
            break;
        case THURSDAY:
            printf("목요일\n");
            break;
        case FRIDAY:
            printf("금요일\n");
            break;
        case SATURDAY:
            printf("토요일\n");
            break;
        default:
        	break;
    }

    return 0;
}