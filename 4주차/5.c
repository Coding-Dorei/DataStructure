#include<stdio.h>
#include<stdlib.h>

int main() {
	int n = 0, m = 0, ** arr = NULL, num = 1;
	scanf("%d%d", &n, &m);
	arr = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)calloc(m, sizeof(int));
	}
	int i = 0, j = 0, row = 0, col = 0;
	while (num <= n * m) {
		i = row;
		j = col;
		while (1) {
			arr[i][j] = num++;
			if (j == 0 || i == n - 1)break;
			else {
				i++;
				j--;
			}
		}
		if (col < m - 1) col++;
		else row++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
}