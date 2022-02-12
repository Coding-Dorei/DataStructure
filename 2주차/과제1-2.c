#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int Generate_one(int* A, int prev_one, int *cnt) {
	int min = prev_one * 0.9;
	int one = rand() % (prev_one - min + 1) + min;
	for (int i = 0; i < one; i++) {
		A[i] = 1;
		*cnt += 1;
	}
	return one;
}

int countOnesButSlow(int **A, int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] == 1) result++;
			else break;
		}
	}
	return result;
}

int countOnes(int** A, int n) {
	int result = 0, j = n - 1;
	for (int i = 0; i < n; i++) {
		while (A[i][j] == 0) j--;
		if (A[i][j] == 1 && j>=0) {
			result += j + 1;
		}
	}
	return result;
}

int main() {
	int** A = NULL, n = 0, tmp = 0, cnt = 0;
	int slow = 0, fast = 0;
	LARGE_INTEGER start = { 0, }, end = { 0, }, diff = { 0, }, ticks = { 0, };
	QueryPerformanceFrequency(&ticks);
	n = 30000;//scanf("%d", &n);                     n = 30000-fast
	tmp = n;
	cnt = 0;
	A = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		A[i] = (int*)calloc(n, sizeof(int));
		tmp = Generate_one(A[i], tmp, &cnt);
	}
	QueryPerformanceCounter(&start);
	fast = countOnes(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12lfsec\n", cnt, fast, (double)diff.QuadPart / (double)ticks.QuadPart);
	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);

	n = 10000;//scanf("%d", &n);                     n = 10000-fast
	tmp = n;
	cnt = 0;
	A = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		A[i] = (int*)calloc(n, sizeof(int));
		tmp = Generate_one(A[i], tmp,&cnt);
	}
	QueryPerformanceCounter(&start);
	fast = countOnes(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12lfsec\n", cnt, fast, (double)diff.QuadPart / (double)ticks.QuadPart);
	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);

	n = 20000;//scanf("%d", &n);                     n = 20000-fast
	tmp = n;
	cnt = 0;
	A = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		A[i] = (int*)calloc(n, sizeof(int));
		tmp = Generate_one(A[i], tmp, &cnt);
	}
	QueryPerformanceCounter(&start);
	fast = countOnes(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12lfsec\n", cnt, fast, (double)diff.QuadPart / (double)ticks.QuadPart);
	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);

	n = 30000;//scanf("%d", &n);                     n = 30000-slow
	tmp = n;
	cnt = 0;
	A = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		A[i] = (int*)calloc(n, sizeof(int));
		tmp = Generate_one(A[i], tmp, &cnt);
	}
	QueryPerformanceCounter(&start);
	slow = countOnesButSlow(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12lfsec\n", cnt, slow, (double)diff.QuadPart / (double)ticks.QuadPart);
	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);

	n = 10000;//scanf("%d", &n);                     n = 10000-slow
	tmp = n;
	cnt = 0;
	A = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		A[i] = (int*)calloc(n, sizeof(int));
		tmp = Generate_one(A[i], tmp, &cnt);
	}
	QueryPerformanceCounter(&start);
	slow = countOnesButSlow(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12lfsec\n", cnt, slow, (double)diff.QuadPart / (double)ticks.QuadPart);
	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);
	
	n = 20000;//scanf("%d", &n);                     n = 20000-slow
	tmp = n;
	cnt = 0;
	A = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		A[i] = (int*)calloc(n, sizeof(int));
		tmp = Generate_one(A[i], tmp,&cnt);
	}
	QueryPerformanceCounter(&start);
	slow = countOnesButSlow(A, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%d %d %.12lfsec\n", cnt, slow, (double)diff.QuadPart / (double)ticks.QuadPart);

	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);
}
/*
8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0
1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0

3
1 1 1
1 1 0
0 0 0
*/