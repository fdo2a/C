#include <stdio.h>
#define ROWS 3 //행(가로)
#define COLS 5 //열(세로)
void printOptions();
int print_seats(int s_array[][COLS]);
int reserve(int s_array[][COLS],int row, int col);
int cancel(int s_array[][COLS], int row, int col);

int main(void)
{
	int seats[ROWS][COLS] = { { 0,0,0,0,0 },{0,0,0,0,0},{0,0,0,0,0} };
	int row = 0;
	int col = 0;
	int select = 0;
	while (1) {
		printOptions();
		printf("메뉴를 선택하세요 :");
		scanf_s("%d", &select);
		if (select == 4) {
			printf("이용해주셔서 감사합니다.\n");
			break;
		}//종료하기
		else if (select == 1) {
			printf("좌석 확인하기\n");
			print_seats(seats);
			printf("\n");
		}
		else if (select == 2) {
			printf("예약을 원하는 자리는?(행, 열) :");
			scanf_s("%d %d", &row,&col);
			reserve(seats,row,col);
			print_seats(seats);
			printf("\n");
		}
		else if (select == 3) {
			printf("예약 취소를 원하는 자리는? (행, 열) :");
			scanf_s("%d %d", &row, &col);
			cancel(seats,row,col);
			print_seats(seats);
			printf("\n");
		}
	}
	return 0;
}

void printOptions() {
	printf("1--좌석 확인하기\n");
	printf("2--예약하기\n");
	printf("3--예약취소하기\n");
	printf("4--종료하기\n");
}
int print_seats(int seats_array[][COLS]) {
	int i, j;
	printf("  | 0 1 2 3 4 \n");
	printf("--------------\n");
	for (i = 0; i < 3; i++) {
		printf("%d |", i);
		for (j = 0; j < 5; j++) {
			printf("%2d", seats_array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int reserve(int seats_array[][COLS], int row, int col) {
	if (seats_array[row][col] == 1) {
		printf("이미 예약된 자리입니다.\n");
		return -1;
		}
	else {
		printf("예약 완료\n");
		seats_array[row][col] = 1;
		return seats_array[row][col];
		}
}
int cancel(int seats_array[][COLS], int row, int col) {
	if (seats_array[row][col] == 0) {
		printf("예약되지 않은 자리입니다.\n");
		return -1;
	}
	else {
		printf("에약 취소되었습니다.\n");
		seats_array[row][col] = 0;
		return seats_array[row][col];
	}
}
