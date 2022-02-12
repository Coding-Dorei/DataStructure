#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

int partition(int*arr, int l, int r) {
	int i = l - 1, j = 0, pivot = arr[r];
	for (j = l; j < r; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr + i, arr + j);
		}
	}
	swap(arr + i + 1, arr + r);
	return i + 1;
}

void quicksort(int* arr, int l, int r) {
	if (l < r) {
		int p = partition(arr, l, r);

		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
}

int main() {
	srand(time(NULL));
	int arr[10] = { 0, };
	for (int* p = arr; p < arr + 10; p++) {
		*p = (((long)rand() << 15 | rand()) % 1000000) + 1;
	}
	LARGE_INTEGER ticksPerSec = { 0, };
	LARGE_INTEGER start = { 0, }, end = { 0, }, diff = { 0, };
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	quicksort(arr, 0, 9);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	for (int* p = arr; p < arr + 10; p++) {
		printf(" %d", *p);
	}
}