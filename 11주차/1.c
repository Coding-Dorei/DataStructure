#include<stdio.h>
#include<stdlib.h>

int isEmpty(int f, int r) {
	return f == r;
}

int isFull(int f, int r, int N) {
	return (r - f + 1) % N == 0;
}

void print(int* queue, int N) {
	for (int* p = queue; p < queue + N; p++) {
		printf(" %d", *p);
	}
	printf("\n");
}

int insert(int* queue, int f, int* r, int N, int elem) {
	if (isFull(f, *r, N)) {
		printf("overflow\n");
		print(queue,  N);
		return -1;
	}
	*r = (*r + 1) % N;
	queue[*r] = elem;
	return 1;
}

int delete_(int* queue, int* f, int r, int N) {
	if (isEmpty(*f, r)) {
		printf("underflow\n");
		return -1;
	}
	*f = (*f + 1) % N;
	queue[*f] = 0;
	return 1;
}

int main() {
	int* queue = NULL, n = 0, q = 0;
	int f = 0, r = 0, elem;
	char mode = 0;
	scanf("%d\n%d\n", &q, &n);
	queue = (int*)calloc(q, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%c", &mode);
		getchar();
		printf("mode :[%c]\n", mode);
		if (mode == 'I') {
			scanf("%d", &elem);
			getchar();
			if (insert(queue, f, &r, q, elem) == -1) return -1;
		}
		else if (mode == 'D') {
			if (delete_(queue, &f, r, q) == -1) return -1;
		}
		else if (mode == 'P') {
			print(queue, q);
		}
	}
	free(queue);
}
/*
6
10
I 10
I 20
P
I 30
I 40
D
P
I 50
I 60
I 70
*/