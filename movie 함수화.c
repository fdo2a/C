#include <stdio.h>

int print_seats();
int researve(int seat);
int cancel(int seat);
int s0 = 0;
int s1 = 0;
int s2 = 0;
int s3 = 0;
int	s4 = 0;	
void printOptions() {
	printf("1--�¼� Ȯ���ϱ�\n");
	printf("2--�����ϱ�\n");
	printf("3--��������ϱ�\n");
	printf("4--�����ϱ�\n");
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
				printf("�̹� ����� �ڸ��Դϴ�.\n");
				return -1;
			}
			else {
				printf("���� �Ϸ�\n");
				s0 = 1;
				return s0;
			}
		else if (ticket == 1)
			if (s1 == 1) {
				printf("�̹� ����� �ڸ��Դϴ�.\n");
				return -1;
			}
			else {
				printf("����Ϸ�\n");
				s1 = 1;
				return s1;
			}
		else if (ticket == 2) 
			if (s2 == 1) {
				printf("�̹� ����� �ڸ��Դϴ�.\n");
				return -1;
			}
			else {
				printf("����Ϸ�\n");
				s2 = 1;
				return s2;
			}
		
		else if (ticket == 3)
			if (s3 == 1) {
				printf("�̹� ����� �ڸ��Դϴ�.\n");
				return -1;
			}
			else {
				printf("����Ϸ�\n");
				s3 = 1;
				return s3;
			}
		else if (ticket == 4)
			if (s4 == 1) {
				printf("�̹� ����� �ڸ��Դϴ�.\n");
				return -1;
			}
			else {
				printf("����Ϸ�\n");
				s4 = 1;
				return s4;
			}
		return -1;
	}
int cancel(int ticket) {
	if (ticket == 0) {
		if (s0 == 1) {
			printf("������Ұ� �Ϸ�Ǿ����ϴ�.\n");
			s0 = 0;
			return s0;
		}
		else
		{
			printf("������� ���� �ڸ��Դϴ�.");
			return -1;
		}
	}
	else if (ticket == 1) {
		if (s1 == 1) {
			printf("������Ұ� �Ϸ�Ǿ����ϴ�.\n");
			s1 = 0;
			return s1;
		}
		else{
			printf("������� ���� �ڸ��Դϴ�.");
			return -1;
		}
	}
	else if (ticket == 2) {
		if (s2 == 1) {
			printf("������Ұ� �Ϸ�Ǿ����ϴ�.\n");
			s2 = 0;
			return s2;
		}
		else
		{
			printf("������� ���� �ڸ��Դϴ�.\n");
			return -1;
		}
	}
	else if (ticket == 3) {
		if (s3 == 1) {
			printf("������Ұ� �Ϸ�Ǿ����ϴ�.\n");
			s3 = 0;
			return s3;
		}
		else
		{
			printf("������� ���� �ڸ��Դϴ�.\n");
			return -1;
		}
	}
	else if (ticket == 4) {
		if (s4 == 1) {
			printf("������Ұ� �Ϸ�Ǿ����ϴ�.\n");
			s4 = 0;
			return s4;
		}
		else {
			printf("������� ���� �ڸ��Դϴ�.\n");
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
		printf("�޴��� �����ϼ��� :");
		scanf_s("%d", &select);
		if (select == 4) {
			printf("�̿����ּż� �����մϴ�.\n");
			break;
		}//�����ϱ�
		else if (select == 1) {
			printf("�¼� Ȯ���ϱ�\n");
			print_seats();
		}//�¼�Ȯ���ϱ�
		else if (select == 2) {
			printf("������ ���ϴ� �ڸ���? :");
			scanf_s("%d", &ticket);
			reserve(ticket);
			print_seats();
		}
		else if (select == 3) {
			printf("���� ��Ҹ� ���ϴ� �ڸ���? :");
			scanf_s("%d", &ticket);
			cancel(ticket);
			print_seats();
		}
	}
	return 0;
}