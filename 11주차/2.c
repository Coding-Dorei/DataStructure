#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int elem;
	struct node* next, *prev;
}node;

node* getNode() {
	node* p = (node*)calloc(1, sizeof(node));
	return p;
}

int isEmpty(node* rear) {
	if (rear == NULL) {
		//printf("Empty\n");
		return 1;
	}
	return 0;
}

void add_front(node** front, node** rear, int elem) {
	node* p = getNode();
	p->elem = elem;
	if (isEmpty(*rear)) {
		*front = *rear = p;
		return;
	}
	p->next = *front;
	(*front)->prev = p;
	*front = p;
	return;
}

void add_rear(node** front, node** rear, int elem) {
	node* p = getNode();
	p->elem = elem;
	if (isEmpty(*rear)) {
		*front = *rear = p;
		return;
	}
	p->prev = *rear;
	(*rear)->next = p;
	*rear = p;
	return;
}

int delete_front(node** front, node**rear) {
	if (isEmpty(*front)) {
		printf("underflow\n");
		return -1;
	}
	node* tmp = *front;
	if (*front == *rear) {
		free(*front);
		*front = *rear = NULL;
	}
	else {
		(*front) = (*front)->next;
		free(tmp);
	}
}

int delete_rear(node ** front ,node** rear) {
	if (isEmpty(*rear)) {
		printf("underflow\n");
		return -1;
	}
	node* tmp = *rear;
	if (*front == *rear) {
		free(*rear);
		*front = *rear = NULL;
	}
	else {
		(*rear) = (*rear)->prev;
		free(tmp);
	}
}

void print(node* front, node *rear) {
	node* p = front;
	while (p != rear) {
		printf(" %d", p->elem);
		p = p->next;
	}
	printf(" %d", p->elem);
	printf("\n");
}

void free_deque(node* front, node* rear) {
	node* p = front;
	while (p != rear) {
		p = p->next;
		free(p->prev);
	}
	free(p);
}

int main() {
	node* front = NULL, * rear = NULL;
	int n = 0, elem = 0;
	char mode = 0, fr = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c", &mode);
		if (mode == 'A') {
			scanf("%c", &fr);
			scanf("%d", &elem);
			getchar();
			if (fr == 'F') add_front(&front, &rear, elem);
			else if (fr == 'R') add_rear(&front, &rear, elem);
		}
		else if (mode == 'D') {
			scanf("%c", &fr);
			getchar();
			if (fr == 'F') {
				if (delete_front(&front, &rear) == -1) {
					free_deque(front, rear);
					return -1;
				}
			}
			else if (fr == 'R') {
				if (delete_rear(&front, &rear) == -1) {
					free_deque(front, rear);
					return -1;
				}
			}
		}
		else if (mode == 'P') {
			print(front, rear);
			getchar();
		}
		//printf("mode : %c%c\n",mode, fr);
	}
	free_deque(front, rear);
}
/*
15
AF 10
AF 20
AF 30
AR 40
AR 50
P
DF
DF
DR
P
DF
DR
DR
*/