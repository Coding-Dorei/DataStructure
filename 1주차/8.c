#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[7];
	int kor, eng, math;
	float avg;
}ST;

int main() {
	int n = 0;
	scanf("%d", &n);
	ST* list = (ST*)calloc(n, sizeof(ST));
	for (ST* p = list; p < list + n; p++) {
		scanf("%s%d%d%d", p->name, &p->kor, &p->eng, &p->math);
		p->avg = (float)(p->kor + p->eng + p->math) / 3;
	}
	for (ST* p = list; p < list + n; p++) {
		printf("%s %.1f ", p->name, p->avg);
		if (p->kor >= 90 || p->eng >= 90 || p->math >= 90) printf("GREAT ");
		if (p->kor < 70 || p->eng < 70 || p->math < 70) printf("BAD ");
		printf("\n");
	}
	free(list);
}