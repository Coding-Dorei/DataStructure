#include<stdio.h>
#include<stdlib.h>

int main() {
	int** arr = NULL, n = 0;
	scanf("%d", &n);
	arr = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)calloc(n, sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/
	int most_one = 0;
	for (int i = 0, j = 0; i < n; i++) {
		if (arr[i][j] == 1) most_one = i;
		while (arr[i][j] == 1) {
			j++;
		}
	}
	printf("%d", most_one);
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