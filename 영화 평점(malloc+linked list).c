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
		printf("영화 제목(끝날때는 엔터) :  ");
		gets(buffer);
		if (buffer[0] == '\0')
			break;
		p = (NODE*)malloc(sizeof(NODE));
		strcpy(p->title, buffer);
		printf("영화 평점 : ");
		gets(buffer);
		score = atof(buffer);
		p->score = score;
		if (head == NULL) {//리스트가 비어 있으면
			head = p;	   //새로운 노드를 첫번째 노드로 만든다
		}
		else {//리스트가 비어있지 않으면
			tail->link = p; // 새로운 노드를 이전 노드의 끝에
		}
		p->link = NULL; //새로운 노드의 링크 필드를 NULL로 설정
		tail = p;
	}//end of while

	printf("================\n");
	printf("제목 평점\n");
	printf("================\n");
	for (p = head; p != NULL; p = p->link) {//리스트에 들어 있는 정보를 모두 출력한다.
		printf("제목 : %s, 평점 = %.1lf\n", p->title, p->score);
	}
	p = head;
	while (p != NULL) {//동적 할당을 반납한다.
		next = p->link;
		free(p);
		p = next;
	}
	return 0;
}
