#include <stdio.h>

void printOptions() {
	printf("1--좌석 예약하기\n");
	printf("2--예약하기\n");
	printf("3--예약취소하기\n");
	printf("4--종료하기\n");
}
int main(void)
{
	int select;
	int ticket;
	int s0 = 0;
	int s1 = 0;
	int s2 = 0;
	int s3 = 0;
	int	s4 = 0;

	while (1) {
		printOptions();
		printf("메뉴를 선택하세요 :");
		scanf_s("%d", &select);
		if (select == 4) {
			printf("이용해주셔서 감사합니다.\n");
			break;
		}
		else if (select == 1) {
			printf("좌석 확인하기\n");	//현재 좌석의 예약 현황을 출력
			printf("0 1 2 3 4\n");
			printf("---------\n");
			printf("%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
		}
		else if (select == 2) {
			printf("예약을 원하는 자리는? :");
			scanf_s("%d", &ticket);
			{
				if (ticket == 0) {
					if (s0 == 1)
						printf("이미 예약된 자리입니다.\n");
					else {
						printf("예약 완료\n");
						s0 = 1;
					}
				}
				else if (ticket == 1) {
					if (s1 == 1)
						printf("이미 예약된 자리입니다.\n");
					else {
						printf("예약완료\n");
						s1 = 1;
					}
				}
				else if (ticket == 2)
					if (s2 == 1)
						printf("이미 예약된 자리입니다.\n");
					else {
						printf("예약완료\n");
						s2 = 1;
					}
				else if (ticket == 3)
					if (s3 == 1)
						printf("이미 예약된 자리입니다.\n");
					else {
						printf("예약완료\n");
						s3 = 1;
					}
				else if (ticket == 4)
					if (s4 == 1)
						printf("이미 예약된 자리입니다.\n");
					else {
						printf("예약완료\n");
						s4 == 1;
					}
			}
			printf("0 1 2 3 4\n");
			printf("---------\n");
			printf("%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
		}
		else if (select == 3) {
			printf("예약 취소를 원하는 자리는? :");
			scanf_s("%d", &ticket);
			{
			if (ticket == 0){ 
				if (s0 == 1) {
					printf("예약취소가 완료되었습니다.\n");
					s0 = 0;
				}
				else
					printf("예약되지 않은 자리입니다.");
				}
			else if (ticket == 1) {
				if (s1 == 1) {
					printf("예약취소가 완료되었습니다.\n");
					s1 = 0;
				}
				else
					printf("예약되지 않은 자리입니다.");
			}
			else if (ticket == 2) {
				if (s2 == 1) {
					printf("예약취소가 완료되었습니다.\n");
					s2 = 0;
				}
				else
					printf("예약되지 않은 자리입니다.\n");
			}
			else if (ticket == 3) {
				if (s3 == 1) {
					printf("예약취소가 완료되었습니다.\n");
					s3 = 0;
				}
				else
					printf("예약되지 않은 자리입니다.\n");
			}
			else if (ticket == 4) {
				if (s4 == 1) {
					printf("예약취소가 완료되었습니다.\n");
					s4 = 0;
				}
				else
					printf("예약되지 않은 자리입니다.\n");
			}
			}
			printf("0 1 2 3 4\n");
			printf("---------\n");
			printf("%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
		}
	}
	return 0;
}