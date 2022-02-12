#include<stdio.h>
#include<stdlib.h>

int* prefixaverage1(int* X, int n) {
	int* A = (int*)calloc(n, sizeof(int)), sum = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += X[j];
		}
		A[i] = (int)(sum / (i + 1));
	}
	return A;
}

int* prefixaverage2(int* X, int n) {
	int* A = (int*)calloc(n, sizeof(int)), sum = 0;
	for (int i = 0; i < n; i++) {
		sum += X[i];
		A[i] = (int)(sum / (i + 1));
	}
	return A;
}

int main() {
	int n = 0, * X = NULL;
	scanf("%d", &n);
	X = (int*)calloc(n, sizeof(int));
	for(int *p = X;p<X+n;p++){
		scanf("%d",p);
	}
	int* A = NULL;
	
	A = prefixaverage1(X, n);
	for(int i = 0;i<n;i++){
		printf("%d ",A[i]);
	}
	free(A);
	printf("\n");
	A = prefixaverage2(X, n);
	for(int i = 0;i<n;i++){
		printf("%d ",A[i]);
	}
	free(A);
	free(X);
}