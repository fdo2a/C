#include <stdio.h>

int print_seats();
int researve(int seat);
int cancel(int seat);
int s0 = 0;
int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;	
void printOptions() {
	printf("1--좌석 확인하기\n");
	printf("2--예약하기\n");
	printf("3--예약취소하기\n");
	printf("4--종료하기\n");
}
int print_seats() {
	printf("0 1 2 3 4\n");
	printf("---------\n");
	printf("%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
	return 0;
}
int reserve(int ticket) {
		if (ticket == 0) 
			if (s0 == 1) {
				printf("이미 예약된 자리입니다.\n");
				return -1;
			}
			else {
				printf("예약 완료\n");
				s0 = 1;
				return s0;
			}
		else if (ticket == 1)
			if (s1 == 1) {
				printf("이미 예약된 자리입니다.\n");
				return -1;
			}
			else {
				printf("예약완료\n");
				s1 = 1;
				return s1;
			}
		else if (ticket == 2) 
			if (s2 == 1) {
				printf("이미 예약된 자리입니다.\n");
				return -1;
			}
			else {
				printf("예약완료\n");
				s2 = 1;
				return s2;
			}
		
		else if (ticket == 3)
			if (s3 == 1) {
				printf("이미 예약된 자리입니다.\n");
				return -1;
			}
			else {
				printf("예약완료\n");
				s3 = 1;
				return s3;
			}
		else if (ticket == 4)
			if (s4 == 1) {
				printf("이미 예약된 자리입니다.\n");
				return -1;
			}
			else {
				printf("예약완료\n");
				s4 = 1;
				return s4;
			}
		return -1;
	}
int cancel(int ticket) {
	if (ticket == 0) {
		if (s0 == 1) {
			printf("예약취소가 완료되었습니다.\n");
			s0 = 0;
			return s0;
		}
		else
		{
			printf("예약되지 않은 자리입니다.");
			return -1;
		}
	}
	else if (ticket == 1) {
		if (s1 == 1) {
			printf("예약취소가 완료되었습니다.\n");
			s1 = 0;
			return s1;
		}
		else{
			printf("예약되지 않은 자리입니다.");
			return -1;
		}
	}
	else if (ticket == 2) {
		if (s2 == 1) {
			printf("예약취소가 완료되었습니다.\n");
			s2 = 0;
			return s2;
		}
		else
		{
			printf("예약되지 않은 자리입니다.\n");
			return -1;
		}
	}
	else if (ticket == 3) {
		if (s3 == 1) {
			printf("예약취소가 완료되었습니다.\n");
			s3 = 0;
			return s3;
		}
		else
		{
			printf("예약되지 않은 자리입니다.\n");
			return -1;
		}
	}
	else if (ticket == 4) {
		if (s4 == 1) {
			printf("예약취소가 완료되었습니다.\n");
			s4 = 0;
			return s4;
		}
		else {
			printf("예약되지 않은 자리입니다.\n");
			return -1;
		}
		print_seats();
	}
	return -1;
}
	
int main(void)
{
	int ticket = 0;
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
			print_seats();
		}//좌석확인하기
		else if (select == 2) {
			printf("예약을 원하는 자리는? :");
			scanf_s("%d", &ticket);
			reserve(ticket);
			print_seats();
		}
		else if (select == 3) {
			printf("예약 취소를 원하는 자리는? :");
			scanf_s("%d", &ticket);
			cancel(ticket);
			print_seats();
		}
	}
	return 0;
}
