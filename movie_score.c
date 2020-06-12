#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S_SIZE 30

typedef struct NODE_t {
	char title[S_SIZE];
	double score;
	struct NODE_t* link;
}NODE;

int main(void)
{
	NODE* head = NULL;
	NODE* tail = NULL;
	NODE* p, * next;
	char buffer[S_SIZE];
	double score;
	while (1) {
		printf("��ȭ ����(�������� ����) :  ");
		gets(buffer);
		if (buffer[0] == '\0')
			break;
		p = (NODE*)malloc(sizeof(NODE));
		strcpy(p->title, buffer);
		printf("��ȭ ���� : ");
		gets(buffer);
		score = atof(buffer);
		p->score = score;
		if (head == NULL) {//����Ʈ�� ��� ������
			head = p;	   //���ο� ��带 ù��° ���� �����
		}
		else {//����Ʈ�� ������� ������
			tail->link = p; // ���ο� ��带 ���� ����� ����
		}
		p->link = NULL; //���ο� ����� ��ũ �ʵ带 NULL�� ����
		tail = p;
	}//end of while

	printf("================\n");
	printf("���� ����\n");
	printf("================\n");
	for (p = head; p != NULL; p = p->link) {//����Ʈ�� ��� �ִ� ������ ��� ����Ѵ�.
		printf("���� : %s, ���� = %.1lf\n", p->title, p->score);
	}
	p = head;
	while (p != NULL) {//���� �Ҵ��� �ݳ��Ѵ�.
		next = p->link;
		free(p);
		p = next;
	}
	return 0;
}