#include <stdio.h>
#include <string.h>

int check(char s[], char a[], char ch);

int main(void)
{
	char solution[100] = "meet at midnight";
	char answer[100] = "____ __ ________";
	char ch;
	while (1) {
		printf("���ڿ��� �Է��Ͻÿ� : %s\n", answer);
		printf("���ڸ� �����Ͻÿ� : ");
		ch = getchar();
		if (check(solution, answer, ch) == 1) {
			printf("���� : %s\n",answer);
			break;
		}
		while (ch = getchar() != '\n' && ch != EOF){} // ��������
	}
	return 0;
}
int check(char s[], char a[], char ch) {
	int i;
	 
	for (i = 0; i < 16; i++) {
		if (s[i] == ch)
			a[i] = ch;
		if (strcmp(s,a)==0)
			return 1;
	}
	return 0;

	
	
	
	
}