#include <stdio.h>
#define ROWS 3 //��(����)
#define COLS 5 //��(����)
#define SIZE 16 // ȸ�� ��
void printOptions();
int print_seats(int s_array[][COLS]);
int reserve(int s_array[][COLS],int row, int col,int id);
int cancel(int s_array[][COLS], int row, int col, int id);
int load_user_info();
int check_login(int id, int passwd);
int binary_search(int n, int key);
struct user_info {
	int id_num;
	int password;
};

struct user_info user[SIZE];

int main(void)
{
	int seats[ROWS][COLS] = { { 0,0,0,0,0 },{0,0,0,0,0},{0,0,0,0,0} };
	int row = 0;
	int col = 0;
	int select = 0;
	int input_id;
	int input_password;	
	while (1) {
		load_user_info();
		printf("�α����� �ϼ���.\n");
		printf("id_num : ");
		scanf_s("%d", &input_id);
		printf("password : ");
		scanf_s("%d", &input_password);
		if (check_login(input_id,input_password)>=0)
			break;
		}
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
			reserve(seats,row,col,input_id);
			print_seats(seats);
			printf("\n");
		}
		else if (select == 3) {
			printf("���� ��Ҹ� ���ϴ� �ڸ���? (��, ��) :");
			scanf_s("%d %d", &row, &col);
			cancel(seats, row, col, input_id);
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
	printf("  | 0  1  2  3  4 \n");
	printf("--------------\n");
	for (i = 0; i < 3; i++) {
		printf("%d |", i);
		for (j = 0; j < 5; j++) {
			printf("%3d", seats_array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int reserve(int seats_array[][COLS], int row, int col,int id) {
	if (seats_array[row][col] == id) {
		printf("�̹� ����� �ڸ��Դϴ�.\n");
		return -1;
		}
	else {
		printf("���� �Ϸ�\n");
		seats_array[row][col] = id;
		return seats_array[row][col];
		}
}
int cancel(int seats_array[][COLS], int row, int col, int id) {
	if (seats_array[row][col] == 0) {
		printf("������� ���� �ڸ��Դϴ�.\n");
		return -1;
	}
	else if (seats_array[row][col] != id) {
		printf("�ٸ� ���̵��� �¼��Դϴ�.\n");
		return -1;
	}
	else {
		printf("���� ��ҵǾ����ϴ�.\n");
		seats_array[row][col] = 0;
		return seats_array[row][col];

	}
}
int load_user_info() {
	int i;
	int id = 10;
	int password = 1004;

	for (i = 0; i < 16; i++) {
		user[i].id_num = id;
		id = id + 10;
		user[i].password = password;
		password = password + 1000;
	}
	return 0;
}
int check_login(int id, int passwd) {	
	if (binary_search(SIZE, id) == -1) {
		printf("�ش� ���̵� �����ϴ�.\n\n");
		return -1;
	}
	else if (user[binary_search(SIZE,id)].password != passwd) {
		printf("�ش� ���̵�� �����ϳ� �н����尡 �ٸ�\n\n");
		return -2;
	}
	else {
		printf("%d�� �ݰ����ϴ�.\n\n", id);
		return id;
	}
}
int binary_search(int n, int key) {
	int low, middle, high, ans;
	low = 0;
	high = n - 1;
	if (key >= 0) {
		while (low <= high) {
			middle = (low + high) / 2;
			if (key == user[middle].id_num) {
				ans = middle;
				return ans;
			}
			else if (key > user[middle].id_num)
				low = middle + 1;
			else
				high = middle - 1;
		}
	}
	return - 1;
}
