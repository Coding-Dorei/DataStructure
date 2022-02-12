#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main() {
	int n = 0, * arr1 = NULL, * arr2 = NULL;
	scanf("%d", &n);
	arr1 = (int*)calloc(n, sizeof(int));
	arr2 = (int*)calloc(n, sizeof(int));
	for (int* p = arr1; p < arr1 + n; p++) {
		scanf("%d", p);
	}
	for (int* p = arr2; p < arr2 + n; p++) {
		scanf("%d", p);
	}
	for (int i = 0; i < n; i++) {
		*(arr1 + i) += *(arr2 + n - 1 - i);
	}
	for (int* p = arr1; p < arr1 + n; p++) {
		printf(" %d", *p);
	}
	free(arr1);
	free(arr2);
}