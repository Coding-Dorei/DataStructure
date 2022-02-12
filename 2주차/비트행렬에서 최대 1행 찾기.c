#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int mostOnes(int** A, int n) {
	int i = 0, j = 0;
	int most = 0;
	int index = 0;
	for (i = 0; i < n; i++) {
		for (j; j < n; j++) {
			if (A[i][j] == 0) {
				break;
			}
		}
		if (A[i][j-1] == 1) {
			most = i;
		}
	}
	return most;
}

int main() {
	int n = 0, ** arr = NULL;
	scanf("%d", &n);
	arr = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)calloc(n, sizeof(int));
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	LARGE_INTEGER ticksPerSec = { 0, };
	LARGE_INTEGER start = { 0, }, end = { 0, }, diff = { 0, };
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	int most = mostOnes(arr, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	printf("%d", most);
}
/*
8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/