#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[10];
	int score;
}student_info;

int main() {
	student_info list[5] = { 0, };
	float avg = 0;
	for (student_info* p = list; p < list + 5; p++) {
		scanf("%s%d", p->name, &p->score);
		avg += p->score;
	}
	avg /= 5;
	for (student_info* p = list; p < list + 5; p++) {
		if (p->score <= avg) printf("%s\n", p->name);
	}
}