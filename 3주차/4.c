#include<stdio.h>
#include<stdlib.h>

void MAX(int* start, int*end, int *tmp_max) {
	if (start < end) {
		*tmp_max = *start > *tmp_max ? *start : *tmp_max;
		MAX(start + 1, end, tmp_max);
	}
}

int main() {
	int n = 0, arr[20] = { 0, }, tmp_max = 0;
	QueryPerformanceFrequency(&tps);
	scanf("%d", &n);
	for (int* p = arr; p < arr + n; p++) {
		scanf("%d", p);
	}
	MAX(arr, arr + n - 1, &tmp_max);
	printf("%d", tmp_max);
}
/*
5
4 1 8 3 7
*/