#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

int* prefixaverage1(int* X, int n) {
	int* A = (int*)calloc(n, sizeof(int)), sum = 0;
	if (A == NULL)
		return NULL;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += X[j];
		}
		A[i] = sum / (i + 1);
	}
	return A;
}

int* prefixaverage2(int* X, int n) {
	int* A = (int*)calloc(n, sizeof(int)), sum = 0;
	if (A == NULL)
		return NULL;
	for (int i = 0; i < n; i++) {
		sum += X[i];
		A[i] = sum / (i + 1);
	}
	return A;
}

int main() {
	srand(time(NULL));
	int n = 0, * X = NULL;
	int* A1 = NULL, * A2 = NULL;
	LARGE_INTEGER start = { 0, }, end = { 0, }, diff = { 0, }, ticks = { 0, };
	QueryPerformanceFrequency(&ticks);
	scanf("%d", &n);
	X = (int*)calloc(n, sizeof(int));
	for (int* p = X; p <= X + n; p++) {
		*p = rand() % 10000 + 1;
	}
	QueryPerformanceCounter(&start);
	A1 = prefixaverage1(X, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12fms\n", (double)diff.QuadPart / (double)ticks.QuadPart * 1000);
	QueryPerformanceCounter(&start);
	A2 = prefixaverage2(X, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12fms", (double)diff.QuadPart / (double)ticks.QuadPart * 1000);
	free(X);
	free(A1);
	free(A2);
}