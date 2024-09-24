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

	int x; // ��
	int y; // ��
	int moveCnt = 0; // ���ºθ� ������ ���� ���°���� Ȯ�ο� 

	InitBoard(board);

	while (1) {
		printf("\n");
		PrintBoard(board);
		printf("Player %c, Stone�� ���� ��, ���� �Է��ϼ���.", currentPlayer);
		scanf("%d %d", &x, &y);

		//��, ���� SIZE �� ��� ��� 
		if (x < 1 || x > SIZE || y < 1 || y > SIZE) {
			printf("�ùٸ� ���� �Է��� �ּ���. \n");
			continue;
		}

		//Stone �� ���� ���  
		if (PlaceStone(board, x - 1 , y - 1, currentPlayer) ){
			moveCnt++;

			//�¸��� ��� 
			if (CheckWin(board, x - 1, y - 1, currentPlayer)) {
				PrintBoard(board);
				printf("Player %c �� �¸��Ͽ����ϴ�. \n", currentPlayer);
				break;
			}

			//���º� �� ���
			if (moveCnt == SIZE * SIZE) {
				printf("���º� �Դϴ�. \n");
				break;
			}

			//Stone�� ���� ���ʰ� �ٲ� ���
			currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
		}
		else {
			printf("�̹� Stone�� ���� ��ġ �Դϴ�. \n");
		}
	}

	return 0;
}

//board �迭�� . �� ������ 
void InitBoard(char board[SIZE][SIZE]) {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			board[i][j] = '.';
		}
	}
}
//���� board �� ��µǴ� �Լ� 
void PrintBoard(char board[SIZE][SIZE]) {
	printf("  ");
	//���� ���ڸ� ǥ��
	for (int i = 0; i < SIZE; i++) {
		printf("%3d", i + 1);
	}
	printf("\n");

	//���� ���ڸ� ǥ�� �� board �迭�� ���ڰ� ǥ�� 
	for (int i = 0; i < SIZE; i++) {
		printf("%2d", i + 1);
		for (int j = 0; j < SIZE; j++) {
			printf("  %c", board[i][j]);
		}
		printf("\n");
	}
}

//board �� stone �� ���� ���, 
int PlaceStone(char board[SIZE][SIZE], int x, int y, char stone) {
	//stone �� �������� ���� ���( . �ΰ��) stone�� ���� 1�� ��ȯ -> ���� �۵��̶� �ǹ� 
	if (board[x][y] == '.') {
		board[x][y] = stone;
		return 1;
	}
	return 0;

}


int CheckWin(char board[SIZE][SIZE], int x, int y, char stone) {
	int horizontal = CheckDirection(board, x, y, stone, 1, 0);
	int vertical = CheckDirection(board, x, y, stone, 0, 1);
	int diagonal1 = CheckDirection(board, x, y, stone, 1, 1); // ��
	int diagonal2 = CheckDirection(board, x, y, stone, 1, -1); // ��

	return horizontal | vertical | diagonal1 | diagonal2;
}

/*
			checkDirection(board, x, y, stone, 1, 0) || // ���� (������) -> x ��ǥ 1�� ����, y ��ǥ �Һ�
           checkDirection(board, x, y, stone, 0, 1) || // ���� (�Ʒ���) -> x ��ǥ �Һ�, y ��ǥ 1�� ����
           checkDirection(board, x, y, stone, 1, 1) || // �밢�� �� (������ �Ʒ�) -> x ��ǥ 1�� ����, y ��ǥ 1�� ����
           checkDirection(board, x, y, stone, 1, -1);  // �밢�� �� (������ ��) -> x ��ǥ 1�� ����, y ��ǥ 1�� ���� 
*/


//Stone �� 5���� ���������� Ȯ���ϴ� �Լ�,
int CheckDirection(char board[SIZE][SIZE], int x, int y, char stone, int dx, int dy) {
	int count = 0;
	// ���� ���� Stone�� �������� -4���� +4���� �� 9ĭ�� Ȯ��
	for (int i = -4; i <= 4; i++) {
		int nx = x + (i * dx);
		int ny = y + (i * dy);

		//nx, ny �� SIZE ���� �ִ��� ����
		//���� Stone�� �ִ� ���, ����, ����, �밢�� ���� 9ĭ���� Stone�� �ִ��� ����. 
		// ..OO. �� ���ӵ� Stone������, 0...0 �� ���ӵ� Stone�̹Ƿ� Count �ؾ� �� 
		// ���� 5 5 �� Stone�� �ְ�, horizontal �� ���η� 6 5 �� stone�� ���� ���, nx �� 5 + ( -4 ~ +4 * 1) , ny�� 5 + 0 �̴�.
		//���� ���� 6 5�� ���� ���, �ٷ� ���� �ִ� 5 5�� Stone�� nx �� for������ ������ �� �����Ƿ� count++ �� �ȴ�. 
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