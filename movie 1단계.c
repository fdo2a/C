#include <stdio.h>

void printOptions() {
	printf("1--�¼� �����ϱ�\n");
	printf("2--�����ϱ�\n");
	printf("3--��������ϱ�\n");
	printf("4--�����ϱ�\n");
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
		printf("�޴��� �����ϼ��� :");
		scanf_s("%d", &select);
		if (select == 4) {
			printf("�̿����ּż� �����մϴ�.\n");
			break;
		}
		else if (select == 1) {
			printf("�¼� Ȯ���ϱ�\n");	//���� �¼��� ���� ��Ȳ�� ���
			printf("0 1 2 3 4\n");
			printf("---------\n");
			printf("%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
		}
		else if (select == 2) {
			printf("������ ���ϴ� �ڸ���? :");
			scanf_s("%d", &ticket);
			{
				if (ticket == 0) {
					if (s0 == 1)
						printf("�̹� ����� �ڸ��Դϴ�.\n");
					else {
						printf("���� �Ϸ�\n");
						s0 = 1;
					}
				}
				else if (ticket == 1) {
					if (s1 == 1)
						printf("�̹� ����� �ڸ��Դϴ�.\n");
					else {
						printf("����Ϸ�\n");
						s1 = 1;
					}
				}
				else if (ticket == 2)
					if (s2 == 1)
						printf("�̹� ����� �ڸ��Դϴ�.\n");
					else {
						printf("����Ϸ�\n");
						s2 = 1;
					}
				else if (ticket == 3)
					if (s3 == 1)
						printf("�̹� ����� �ڸ��Դϴ�.\n");
					else {
						printf("����Ϸ�\n");
						s3 = 1;
					}
				else if (ticket == 4)
					if (s4 == 1)
						printf("�̹� ����� �ڸ��Դϴ�.\n");
					else {
						printf("����Ϸ�\n");
						s4 == 1;
					}
			}
			printf("0 1 2 3 4\n");
			printf("---------\n");
			printf("%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
		}
		else if (select == 3) {
			printf("���� ��Ҹ� ���ϴ� �ڸ���? :");
			scanf_s("%d", &ticket);
			{
			if (ticket == 0){ 
				if (s0 == 1) {
					printf("������Ұ� �Ϸ�Ǿ����ϴ�.\n");
					s0 = 0;
				}
				else
					printf("������� ���� �ڸ��Դϴ�.");
				}
			else if (ticket == 1) {
				if (s1 == 1) {
					printf("������Ұ� �Ϸ�Ǿ����ϴ�.\n");
					s1 = 0;
				}
				else
					printf("������� ���� �ڸ��Դϴ�.");
			}
			else if (ticket == 2) {
				if (s2 == 1) {
					printf("������Ұ� �Ϸ�Ǿ����ϴ�.\n");
					s2 = 0;
				}
				else
					printf("������� ���� �ڸ��Դϴ�.\n");
			}
			else if (ticket == 3) {
				if (s3 == 1) {
					printf("������Ұ� �Ϸ�Ǿ����ϴ�.\n");
					s3 = 0;
				}
				else
					printf("������� ���� �ڸ��Դϴ�.\n");
			}
			else if (ticket == 4) {
				if (s4 == 1) {
					printf("������Ұ� �Ϸ�Ǿ����ϴ�.\n");
					s4 = 0;
				}
				else
					printf("������� ���� �ڸ��Դϴ�.\n");
			}
			}
			printf("0 1 2 3 4\n");
			printf("---------\n");
			printf("%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
		}
	}
	return 0;
}