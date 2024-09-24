#include <stdio.h>

#define SIZE 15

void InitBoard(char board[SIZE][SIZE]);
void PrintBoard(char board[SIZE][SIZE]);
int PlaceStone(char board[SIZE][SIZE], int x, int y, char stone);
int CheckDirection(char board[SIZE][SIZE], int x, int y, char stone, int dx, int dy);
int CheckWin(char board[SIZE][SIZE], int x, int y, char stone);



int main(void) {
	char board[SIZE][SIZE];
	char currentPlayer = 'X';

	int x; // 행
	int y; // 열
	int moveCnt = 0; // 무승부를 가르기 위한 몇수째인지 확인용 

	InitBoard(board);

	while (1) {
		printf("\n");
		PrintBoard(board);
		printf("Player %c, Stone을 놓을 행, 열을 입력하세요.", currentPlayer);
		scanf("%d %d", &x, &y);

		//행, 열이 SIZE 를 벗어난 경우 
		if (x < 1 || x > SIZE || y < 1 || y > SIZE) {
			printf("올바른 값을 입력해 주세요. \n");
			continue;
		}

		//Stone 을 놓은 경우  
		if (PlaceStone(board, x - 1 , y - 1, currentPlayer) ){
			moveCnt++;

			//승리한 경우 
			if (CheckWin(board, x - 1, y - 1, currentPlayer)) {
				PrintBoard(board);
				printf("Player %c 가 승리하였습니다. \n", currentPlayer);
				break;
			}

			//무승부 인 경우
			if (moveCnt == SIZE * SIZE) {
				printf("무승부 입니다. \n");
				break;
			}

			//Stone을 놓아 차례가 바뀐 경우
			currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
		}
		else {
			printf("이미 Stone을 놓은 위치 입니다. \n");
		}
	}

	return 0;
}

//board 배열에 . 을 삽입함 
void InitBoard(char board[SIZE][SIZE]) {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			board[i][j] = '.';
		}
	}
}
//실제 board 가 출력되는 함수 
void PrintBoard(char board[SIZE][SIZE]) {
	printf("  ");
	//행의 숫자를 표시
	for (int i = 0; i < SIZE; i++) {
		printf("%3d", i + 1);
	}
	printf("\n");

	//열의 숫자를 표시 및 board 배열의 문자값 표시 
	for (int i = 0; i < SIZE; i++) {
		printf("%2d", i + 1);
		for (int j = 0; j < SIZE; j++) {
			printf("  %c", board[i][j]);
		}
		printf("\n");
	}
}

//board 에 stone 을 놓는 경우, 
int PlaceStone(char board[SIZE][SIZE], int x, int y, char stone) {
	//stone 이 놓여있지 않은 경우( . 인경우) stone을 놓고 1을 반환 -> 정상 작동이란 의미 
	if (board[x][y] == '.') {
		board[x][y] = stone;
		return 1;
	}
	return 0;

}


int CheckWin(char board[SIZE][SIZE], int x, int y, char stone) {
	int horizontal = CheckDirection(board, x, y, stone, 1, 0);
	int vertical = CheckDirection(board, x, y, stone, 0, 1);
	int diagonal1 = CheckDirection(board, x, y, stone, 1, 1); // ↘
	int diagonal2 = CheckDirection(board, x, y, stone, 1, -1); // ↙

	return horizontal | vertical | diagonal1 | diagonal2;
}

/*
			checkDirection(board, x, y, stone, 1, 0) || // 가로 (오른쪽) -> x 좌표 1씩 증가, y 좌표 불변
           checkDirection(board, x, y, stone, 0, 1) || // 세로 (아래쪽) -> x 좌표 불변, y 좌표 1씩 증가
           checkDirection(board, x, y, stone, 1, 1) || // 대각선 ↘ (오른쪽 아래) -> x 좌표 1씩 증가, y 좌표 1씩 증가
           checkDirection(board, x, y, stone, 1, -1);  // 대각선 ↙ (오른쪽 위) -> x 좌표 1씩 증가, y 좌표 1씩 감소 
*/


//Stone 이 5개로 놓여졌는지 확인하는 함수,
int CheckDirection(char board[SIZE][SIZE], int x, int y, char stone, int dx, int dy) {
	int count = 0;
	// 현재 놓인 Stone을 기준으로 -4에서 +4까지 총 9칸을 확인
	for (int i = -4; i <= 4; i++) {
		int nx = x + (i * dx);
		int ny = y + (i * dy);

		//nx, ny 가 SIZE 내에 있는지 여부
		//기존 Stone이 있는 경우, 가로, 세로, 대각선 기준 9칸내에 Stone이 있는지 여부. 
		// ..OO. 도 연속된 Stone이지만, 0...0 도 연속된 Stone이므로 Count 해야 함 
		// 만약 5 5 에 Stone이 있고, horizontal 인 가로로 6 5 에 stone을 놓은 경우, nx 는 5 + ( -4 ~ +4 * 1) , ny는 5 + 0 이다.
		//따라서 새로 6 5에 놓은 경우, 바로 옆에 있는 5 5의 Stone을 nx 의 for문에서 감지할 수 있으므로 count++ 가 된다. 
		if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == stone) {
			count++;
			if (count == 5) {
				return 1;
			}
		}
		else {
			count = 0;
		}
	}
	return 0;
}