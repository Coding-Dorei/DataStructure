#include<stdio.h>
#include<stdlib.h>

void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

void reverse(int *arr, int start, int end) {
	int n = end - start;
	for (int i = 0; i < n / 2 + 1; i++) {
		swap(arr + start + i, arr + end - i);
	}
}

int main() {
	int n = 0, m = 0,  a = 0, b = 0;
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	for (int* p = arr; p < arr + n; p++) {
		scanf("%d", p);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		reverse(arr, a, b);
	}
	for (int* p = arr; p < arr + n; p++) {
		printf("%d ", *p);
	}
	free(arr);
}
/*
10
3 81 9 12 0 -9 36 33 91 10
3
3 7 4 5 0 4
*/