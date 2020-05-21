#include <stdio.h>
#define ROWS 3 //��(����)
#define COLS 5 //��(����)
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
		printf("�޴��� �����ϼ��� :");
		scanf_s("%d", &select);
		if (select == 4) {
			printf("�̿����ּż� �����մϴ�.\n");
			break;
		}//�����ϱ�
		else if (select == 1) {
			printf("�¼� Ȯ���ϱ�\n");
			print_seats(seats);
			printf("\n");
		}
		else if (select == 2) {
			printf("������ ���ϴ� �ڸ���?(��, ��) :");
			scanf_s("%d %d", &row,&col);
			reserve(seats,row,col);
			print_seats(seats);
			printf("\n");
		}
		else if (select == 3) {
			printf("���� ��Ҹ� ���ϴ� �ڸ���? (��, ��) :");
			scanf_s("%d %d", &row, &col);
			cancel(seats,row,col);
			print_seats(seats);
			printf("\n");
		}
	}
	return 0;
}

void printOptions() {
	printf("1--�¼� Ȯ���ϱ�\n");
	printf("2--�����ϱ�\n");
	printf("3--��������ϱ�\n");
	printf("4--�����ϱ�\n");
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
		printf("�̹� ����� �ڸ��Դϴ�.\n");
		return -1;
		}
	else {
		printf("���� �Ϸ�\n");
		seats_array[row][col] = 1;
		return seats_array[row][col];
		}
}
int cancel(int seats_array[][COLS], int row, int col) {
	if (seats_array[row][col] == 0) {
		printf("������� ���� �ڸ��Դϴ�.\n");
		return -1;
	}
	else {
		printf("���� ��ҵǾ����ϴ�.\n");
		seats_array[row][col] = 0;
		return seats_array[row][col];
	}
}
