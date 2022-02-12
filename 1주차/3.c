#include<stdio.h>
#include<stdlib.h>

void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

int main() {
	int N = 0, * arr = NULL;
	scanf("%d", &N);
	arr = (int*)calloc(N, sizeof(int));
	for (int* p = arr; p < arr + N; p++) {
		scanf("%d", p);
	}
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	swap(arr + a, arr + b);
	for (int* p = arr; p < arr + N; p++) {
		printf(" %d", *p);
	}
	free(arr);
}