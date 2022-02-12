#include<stdio.h>

void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

void ABC(int* arr, int k) {
	int *max = (arr + k);
	for (int* p = arr + k; p < arr + 10; p++) {
		if (*max < *p) {
			max = p;
		}
	}
	swap(arr + k, max);
}

int main() {
	int arr[10] = { 0,0 };
	for (int* p = arr; p < arr + 10; p++) {
		scanf("%d", p);
	}
	for (int i = 0; i < 9; i++) {
		ABC(arr, i);
	}
	for (int* p = arr; p < arr + 10; p++) {
		printf(" %d", *p);
	}
}