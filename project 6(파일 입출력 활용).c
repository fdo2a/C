#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROWS 3 //행(가로)
#define COLS 5 //열(세로)
#define SIZE 10 // 회원 수
typedef struct user_info {
	int id_num;		//회원번호
	char id[SIZE];	//회원 아이디. 10자 이내, 회원번호와 별도
	char password[SIZE];	//10자 이내
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
		printf("로그인을 하세요.\n");
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
		printf("메뉴를 선택하세요 : ");
		scanf_s("%d", &select);
		printf("\n");
		while ((c = getchar()) != '\n' && (c != EOF)) {};
		if (select == 5) {
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
			scanf("%c %d", &row, &col);
			while ((c = getchar()) != '\n' && (c != EOF)) {}
			reserve(seats, row, col, user[num].id_num);
			save_reservation_info(seats);
			print_seats(seats);
			printf("\n");
		}
		else if (select == 3) {
			printf("예약 취소를 원하는 자리는? (행, 열) :");
			scanf("%c %d", &row, &col);
			while ((c = getchar()) != '\n' && (c != EOF)) {};
			cancel(seats, row, col, user[num].id_num);
			save_reservation_info(seats);
			print_seats(seats);
			printf("\n");
		}
		else if (select == 4) {
			printf("로그아웃 되었습니다.\n");
			while (1) {
				printf("로그인을 하세요.\n");
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
	printf("1--좌석 확인하기\n");
	printf("2--예약하기\n");
	printf("3--예약취소하기\n");
	printf("4--다른 사용자로 로그인하기\n");
	printf("5--종료하기\n");
}
int load_user_info(INFO user[], int size) {
	int i, j, k, temp, least;
	char temp1[10];
	char temp2[10];

	FILE* fp;
	fp = fopen("user_data.txt", "r");
	if (fp == NULL) {
		fprintf(stderr,"파일 열기 실패\n","user_data.txt");
		return -1;
	}
	else
		for (k = 0; k < SIZE; k++)
		fscanf(fp, "%d %s %s\n", &user[k].id_num, user[k].id, user[k].password); //ok
		for (i = 0; i < SIZE - 1; i++) {
				//최소값 찾기
			least = i;
			for (j = i + 1; j < SIZE; j++)
				if (user[j].id_num < user[least].id_num)							
					least = j;
				//교환
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
		fprintf(stderr,"파일 오픈 실패\n","reservation_data.txt");
		return -1;
	}
	//오픈한 data를 seats에 넣어주기
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
		fprintf(stderr, "파일 오픈 실패\n", "reservation_data.txt");
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
		printf("해당 아이디가 없습니다.\n\n");
		return -1;
	}
	else if (strcmp(user[value].password, passwd) != 0) {
		printf("해당 아이디는 존재하나 패스워드가 다름\n\n");
		return -2;
	}
	else {
		printf("user%d님 반갑습니다.\n\n", user[value].id_num);
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
		printf("이미 예약된 자리입니다.\n\n");
		return -1;
	}
	else {
		printf("예약 완료\n\n");
		seats_array[row-65][col] = id_num;
		return seats_array[row-65][col];
	}
}
int cancel(int seats_array[][COLS], char row, int col, int id_num) {
	if (seats_array[row-65][col] == 0) {
		printf("예약되지 않은 자리입니다.\n\n");
		return -1;
	}
	else if (seats_array[row-65][col] != id_num) {
		printf("다른 아이디의 좌석입니다.\n\n");
		return -1;
	}
	else {
		printf("에약 취소되었습니다.\n\n");
		seats_array[row-65][col] = 0;
		return seats_array[row-65][col];

	}
}

