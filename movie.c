#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROWS 3 //��(����)
#define COLS 5 //��(����)
#define SIZE 10 // ȸ�� ��
typedef struct user_info {
	int id_num;		//ȸ����ȣ
	char id[SIZE];	//ȸ�� ���̵�. 10�� �̳�, ȸ����ȣ�� ����
	char password[SIZE];	//10�� �̳�
}INFO;
void printOptions();
int load_user_info(INFO user[], int size);
int load_reservation_info(int s[][COLS]);
int save_reservation_info(int s[][COLS]);
int check_login(INFO user[], char id[], char passwd[]);
int binary_search(INFO user[], int n, char key[]);
int print_seats(int s_array[][COLS]);
int reserve(int s_array[][COLS], char row, int col, int id_num);
int cancel(int s_array[][COLS], char row, int col, int id_num);


int main(void)
{
	int seats[ROWS][COLS]; 
	char row;
	int col = 0;
	int select = 0;
	int c;
	char input_id[20];
	char input_password[20];
	INFO user[SIZE];

	load_reservation_info(seats);
	load_user_info(user, SIZE);
		if (load_user_info(user,SIZE) < 0)
			exit(-1);
	while (1) {
		printf("�α����� �ϼ���.\n");
		printf("id_num : ");
		scanf("%s", input_id);
		while ((c = getchar()) != '\n' && (c != EOF)) {};
		printf("password : ");
		scanf("%s", input_password);
		if (check_login(user, input_id, input_password) >= 0)
			break;
	}
	while (1) {
		int num = binary_search(user, SIZE, input_id);
		load_reservation_info(seats);
		printOptions();
		printf("�޴��� �����ϼ��� : ");
		scanf_s("%d", &select);
		printf("\n");
		while ((c = getchar()) != '\n' && (c != EOF)) {};
		if (select == 5) {
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
			reserve(seats, row, col, user[num].id_num);
			save_reservation_info(seats);
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
		else if (select == 4) {
			printf("�α׾ƿ� �Ǿ����ϴ�.\n");
			while (1) {
				printf("�α����� �ϼ���.\n");
				printf("id_num : ");
				scanf("%s", input_id);
				while ((c = getchar()) != '\n' && (c != EOF)) {};
				printf("password : ");
				scanf("%s", input_password);
				if (check_login(user, input_id, input_password) >= 0)
					break;
			}
		}
	}
	return 0;
}

void printOptions() {
	printf("1--�¼� Ȯ���ϱ�\n");
	printf("2--�����ϱ�\n");
	printf("3--��������ϱ�\n");
	printf("4--�ٸ� ����ڷ� �α����ϱ�\n");
	printf("5--�����ϱ�\n");
}
int load_user_info(INFO user[], int size) {
	int i, j, k, temp, least;
	char temp1[10];
	char temp2[10];

	FILE* fp;
	fp = fopen("user_data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr,"���� ���� ����\n","user_data.txt");
		return -1;
	}
	else
		for (k = 0; k < SIZE; k++)
		fscanf(fp, "%d %s %s\n", &user[k].id_num, user[k].id, user[k].password); //ok
		for (i = 0; i < SIZE - 1; i++) {
				//�ּҰ� ã��
			least = i;
			for (j = i + 1; j < SIZE; j++)
				if (user[j].id_num < user[least].id_num)							
					least = j;
				//��ȯ
			temp = user[i].id_num;
			strcpy(temp1, user[i].id);
			strcpy(temp2, user[i].password);
			user[i].id_num = user[least].id_num;
			strcpy(user[i].id, user[least].id);
			strcpy(user[i].password, user[least].password);
			user[least].id_num = temp;		
			strcpy(user[least].id, temp1);					
			strcpy(user[least].password, temp2);
			}
			return SIZE;
	fclose(fp);
}
int load_reservation_info(int s[][COLS]) {
	int i, j;
	FILE* fp;
	fp = fopen("reservation_data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr,"���� ���� ����\n","reservation_data.txt");
		return -1;
	}
	//������ data�� seats�� �־��ֱ�
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++) {
			fscanf(fp, "%d", &s[i][j]);
		}
}
int save_reservation_info(int s[][COLS]) {
	FILE* fp;
	int i, j, k=0;
	fp = fopen("reservation_data.txt", "r+");
	if (fp == NULL) {
		fprintf(stderr, "���� ���� ����\n", "reservation_data.txt");
		return -1;
	}
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			fprintf(fp, "%d ", s[i][j]);
			k++;
			if (k == 5) {
				fprintf(fp, "\n");
				k = 0;
			}
		}
		
	}
	fclose(fp);
}
int check_login(INFO user[], char id[], char passwd[]) {
	int value;
	value = binary_search(user, SIZE, id);
	if (value == -1) {
		printf("�ش� ���̵� �����ϴ�.\n\n");
		return -1;
	}
	else if (strcmp(user[value].password, passwd) != 0) {
		printf("�ش� ���̵�� �����ϳ� �н����尡 �ٸ�\n\n");
		return -2;
	}
	else {
		printf("user%d�� �ݰ����ϴ�.\n\n", user[value].id_num);
		return user[value].id_num;
	}
}
int binary_search(INFO user[], int n, char key[]) {
	;
	int low, middle, high, result;
	low = 0;
	high = n - 1;

	while (low <= high) {
		middle = (low + high) / 2;
		result = strcmp(key, user[middle].id);
		if (result == 0) {
			key[10] = user[middle].id;
			return middle;
		}
		else if (result > 0)
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;

}
int print_seats(int seats_array[][COLS]) {
	char i;
	int j;
	printf("  |   0   1   2   3   4 \n");
	printf("--------------------------\n");
	for (i = 65; i < 68; i++) {
		printf("%c |", i);
		for (j = 0; j < 5; j++) {
			printf("%4d", seats_array[i-65][j]);
		}
		printf("\n");
	}
	return 0;
}
int reserve(int seats_array[][COLS], char row, int col, int id_num) {
	if (seats_array[row-65][col] == id_num) {
		printf("�̹� ����� �ڸ��Դϴ�.\n\n");
		return -1;
	}
	else {
		printf("���� �Ϸ�\n\n");
		seats_array[row-65][col] = id_num;
		return seats_array[row-65][col];
	}
}
int cancel(int seats_array[][COLS], char row, int col, int id_num) {
	if (seats_array[row-65][col] == 0) {
		printf("������� ���� �ڸ��Դϴ�.\n\n");
		return -1;
	}
	else if (seats_array[row-65][col] != id_num) {
		printf("�ٸ� ���̵��� �¼��Դϴ�.\n\n");
		return -1;
	}
	else {
		printf("���� ��ҵǾ����ϴ�.\n\n");
		seats_array[row-65][col] = 0;
		return seats_array[row-65][col];

	}
}

