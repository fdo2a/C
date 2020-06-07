#include <stdio.h>
#include <string.h>
#define ROWS 3 //��(����)
#define COLS 5 //��(����)
#define SIZE 10 // ȸ�� ��
typedef struct user_info {
	int id_num;		//ȸ����ȣ
	char id[SIZE];	//ȸ�� ���̵�. 10�� �̳�, ȸ����ȣ�� ����
	char password[SIZE];	//10�� �̳�
}INFO;
void printOptions();
int print_seats(int s_array[][COLS]);
int reserve(int s_array[][COLS], char row, int col,int id_num);
int cancel(int s_array[][COLS], char row, int col, int id_num);
int load_user_info(INFO user[], int size);
int check_login(INFO user[], char id[], char passwd[]);
int binary_search(INFO user[], int n, char key[]);

int main(void)
{
	int seats[ROWS][COLS] = { { 0,0,0,0,0 },{0,0,0,0,0},{0,0,0,0,0} };
	char row;
	int col = 0;
	int select = 0;
	int c;
	char input_id[10];
	char input_password[10];	
	
	INFO user[SIZE];
	
	load_user_info(user,SIZE);
	while (1) {
		printf("�α����� �ϼ���.\n");
		printf("id_num : ");
		scanf("%s", input_id);
		printf("password : ");
		scanf("%s", input_password);
		if (check_login(user,input_id,input_password)>=0)
			break;
		}
	int num = binary_search(user, SIZE, input_id);
	while (1) {
		printOptions();
		printf("�޴��� �����ϼ��� :");
		scanf_s("%d", &select);
		while ((c = getchar()) != '\n' && (c != EOF)) {};
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
			scanf("%c %d", &row, &col);
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			reserve(seats,row,col,user[num].id_num);
			print_seats(seats);
			printf("\n");
		}
		else if (select == 3) {
			printf("���� ��Ҹ� ���ϴ� �ڸ���? (��, ��) :");
			scanf("%c %d", &row, &col);
			while ((c = getchar()) != '\n' && (c != EOF)) {};
			cancel(seats, row, col, user[num].id_num);
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
	char i;
	int j;
	printf("  |   0   1   2   3   4 \n");
	printf("--------------------------\n");
	for (i = 65; i < 68; i++) {
		printf("%c |", i);
		for (j = 0; j < 5; j++) {
			printf("%4d", seats_array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int reserve(int seats_array[][COLS], char row, int col,int id_num) {
	if (seats_array[row][col] == id_num) {
		printf("�̹� ����� �ڸ��Դϴ�.\n\n");
		return -1;
		}
	else {
		printf("���� �Ϸ�\n\n");
		seats_array[row][col] = id_num;
		return seats_array[row][col];
		}
}
int cancel(int seats_array[][COLS], char row, int col, int id_num) {
	if (seats_array[row][col] == 0) {
		printf("������� ���� �ڸ��Դϴ�.\n\n");
		return -1;
	}
	else if (seats_array[row][col] != id_num) {
		printf("�ٸ� ���̵��� �¼��Դϴ�.\n\n");
		return -1;
	}
	else {
		printf("���� ��ҵǾ����ϴ�.\n\n");
		seats_array[row][col] = 0;
		return seats_array[row][col];

	}
}
int load_user_info(INFO user[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		user[i].id_num = (i + 1) * 10;
		sprintf(user[i].id, "user%d", i);
		sprintf(user[i].password, "pass%d", i);
	}
	return 0;
}
int check_login(INFO user[], char id[], char passwd[]) {
	int value;
	value = binary_search(user, SIZE, id);
	if (value == -1) {
		printf("�ش� ���̵� �����ϴ�.\n\n");
		return -1;
	}
	else if (strcmp(user[value].password, passwd)!=0) {
		printf("�ش� ���̵�� �����ϳ� �н����尡 �ٸ�\n\n");
		return -2;
	}
	else {
		printf("user%d�� �ݰ����ϴ�.\n\n", user[value].id_num);
		return user[value].id_num;
	}
}
int binary_search(INFO user[],int n, char key[]) {
;
	int low, middle, high, result;
	low = 0;
	high = n - 1;

	while (low <= high) {
		middle = (low + high) / 2;
		result = strcmp(key ,user[middle].id);
		if (result == 0) {
			key[10] = user[middle].id;
			return middle;
		}
		else if (result > 0)
			low = middle + 1;
		else
			high = middle - 1;
		}
	return - 1;
	
}
