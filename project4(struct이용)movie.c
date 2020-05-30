#include <stdio.h>
#define ROWS 3 //행(가로)
#define COLS 5 //열(세로)
#define SIZE 16 // 회원 수
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
		printf("로그인을 하세요.\n");
		printf("id_num : ");
		scanf_s("%d", &input_id);
		printf("password : ");
		scanf_s("%d", &input_password);
		if (check_login(input_id,input_password)>=0)
			break;
		}
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
			reserve(seats,row,col,input_id);
			print_seats(seats);
			printf("\n");
		}
		else if (select == 3) {
			printf("예약 취소를 원하는 자리는? (행, 열) :");
			scanf_s("%d %d", &row, &col);
			cancel(seats, row, col, input_id);
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
		printf("이미 예약된 자리입니다.\n");
		return -1;
		}
	else {
		printf("예약 완료\n");
		seats_array[row][col] = id;
		return seats_array[row][col];
		}
}
int cancel(int seats_array[][COLS], int row, int col, int id) {
	if (seats_array[row][col] == 0) {
		printf("예약되지 않은 자리입니다.\n");
		return -1;
	}
	else if (seats_array[row][col] != id) {
		printf("다른 아이디의 좌석입니다.\n");
		return -1;
	}
	else {
		printf("에약 취소되었습니다.\n");
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
		printf("해당 아이디가 없습니다.\n\n");
		return -1;
	}
	else if (user[binary_search(SIZE,id)].password != passwd) {
		printf("해당 아이디는 존재하나 패스워드가 다름\n\n");
		return -2;
	}
	else {
		printf("%d님 반갑습니다.\n\n", id);
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
