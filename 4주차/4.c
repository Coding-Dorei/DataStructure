#include<stdio.h>
#include<stdlib.h>

void spiral(int** arr, int n, int m,int i, int j, char direction, int num, int max) {
	if (num > max) {
		//printf("num = %d\n" ,num);
		return;
	}

	if (direction == '+') {
		for (int k = 0; k < m; k++) {
			arr[i][j++] = num++;
		}
		num--;
		j--;
		for (int k = 0; k < n; k++) {
			arr[i++][j] = num++;
		}
		i--;
		
		spiral(arr, n - 1, m - 1, i, j-1, '-', num, max);
	}
	else if (direction == '-') {
		for (int k = 0; k < m; k++) {
			arr[i][j--] = num++;
		}
		num--;
		j++;
		for (int k = 0; k < n; k++) {
			arr[i--][j] = num++;
		}
		i++;

		spiral(arr, n - 1, m - 1, i, j+1, '+', num, max);
	}
}

int main() {
	int n = 0, m = 0, ** arr = NULL, num = 1, i = 0, j = 0;
	scanf("%d%d", &n,&m);
	arr = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; i++) {
		arr[i] = (int*)calloc(m, sizeof(int));
	}
	spiral(arr, n, m, 0, 0, '+', 1, m*n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		free(arr[i]);
	}
	free(arr);
}