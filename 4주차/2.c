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
	int* arr = NULL, n = 0, m = 0;
	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));
	for (int* p = arr; p < arr + n; p++) {
		scanf("%d", p);
	}
	scanf("%d", &m);
	int* position = (int*)calloc(m, sizeof(int));
	for (int* q = position; q < position + m; q++) {
		scanf("%d", q);
	}
	for (int i = 1; i < m; i++) {
		swap(arr + position[0], arr + position[i]);
	}
	for (int* p = arr; p < arr + n; p++) {
		printf("%d ", *p);
	}
	free(arr);
	free(position);

}
/*
6
0 20 40 30 10 50
4
1 2 4 1
*/