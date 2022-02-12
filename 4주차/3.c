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
	int** arr = NULL, n = 0, m = 1;
	scanf("%d", &n);
	arr = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)calloc(n, sizeof(int));
		for (int j = 0; j < n; j++) {
			arr[i][j] = m++;
		}
		if (i % 2 == 1) reverse(arr[i], 0, n - 1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
}
/*
6
0 20 40 30 10 50
4
1 2 4 1
*/