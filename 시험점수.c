#include <stdio.h>
#define EXAM 3
#define STUDENT 5

int find_min(int score_array[EXAM][STUDENT], int exam);
int find_max(int score_array[EXAM][STUDENT], int exam);
double find_avg(int score_array[EXAM][STUDENT], int exam);

int main(void)
{
	int score[EXAM][STUDENT] = { {60,80,43,78,93},{75,59,81,77,81},{83,74,97,73,81} };
	int num;
	printf("시험번호를 입력하시오 (0 ~ 2) : ");
	scanf_s("%d", &num);
	printf("최저점수 : %d점\n", find_min(score, num));
	printf("최고점수 : %d점\n", find_max(score, num));
	printf("평균점수 : %lf점\n", find_avg(score, num));

	return 0;
}

int find_min(int score_array[][STUDENT], int exam) {
	int i, least;
	least = score_array[exam][0];
	for (i = 0; i < STUDENT; i++) {
		if (score_array[exam][i] < least)
				least = score_array[exam][i];
	}
	return least;
}

int find_max(int score_array[][STUDENT], int exam) {
	int i, max;
	max = score_array[exam][0];
	for (i = 0; i < STUDENT; i++) {
			if (score_array[exam][i] > max)
				max = score_array[exam][i];
	}
	return max;
}

double find_avg(int score_array[][STUDENT], int exam) {
	int i;
	double sum=0, avg;
	for (i = 0; i < STUDENT; i++)
		sum = sum + score_array[exam][i];
	avg = sum / STUDENT;

	return avg;
}