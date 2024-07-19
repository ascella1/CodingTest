#include <stdio.h>
#include <windows.h>

typedef enum{ // enum LockState 이런 형식으로 선언하는 것 보다 typedef 를 사용하면 더 편한듯. 
    LOCKED,
    UNLOCKED,
    ERROR_
}LockState;

LockState checkCode(const char *input, const char *correctInput);
//input 변수에 포인터 사용 이유 -> 문자열은 배열로 정의되는데, 포인터를 통해 배열의 첫번째 인덱스의 주소만 
//전달하는것이 효율적 (배열 전체를 복사후 사용하지 않고, 배열의 주소만 전달하여 메모리 적으로도 효율적)
//const 사용 이유 -> 문자열 수정 방지를 통해 안정성 높임

int main(void){
    LockState currentState = LOCKED;
    char input[100];
    char correctInput[100];

    printf("correctInput 을 설정해주세요 : ");
    scanf("%s", correctInput);

    while(1){
        switch (currentState){
            case LOCKED:
                printf("LOCKED 상태 / 비밀번호 입력 : ");
                scanf("%s", input);
                currentState = checkCode(input, correctInput);
                break;
            case UNLOCKED:
                printf("UNLOCKED 상태 / 잠금이 해제됨\n");
                Sleep(3000);
                printf("LOCKED 상태 / 3초가 지났으므로 다시 잠금\n");
                currentState = LOCKED;
                break;
            case ERROR_:
                printf("ERROR 상태 / 비밀번호가 틀립니다. \n");
                currentState = LOCKED;
                break;
            default:
                break;
        }
    }

    return 0;
}

LockState checkCode(const char *input, const char *correctInput){
    if(strcmp(input, correctInput) == 0){//strcmp() -> 두 문자열 비교 함수, 완전히 같다면 0, 다르면 음수 혹은 양수값 
        return UNLOCKED;
    }else{
        return ERROR_;
    }
}
