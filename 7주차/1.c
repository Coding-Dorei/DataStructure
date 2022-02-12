#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* next;
	int elem;
}node;

node* getNode() {
	node* p = (node*)calloc(1, sizeof(node));
	return p;
}

void print(node* head) {
	node* p = head;
	if (p == NULL) printf("NULL pointer\n");
	while (p != NULL) {
		printf("%d ", p->elem);
		p = p->next;
	}
}

void addLast(node** head, int elem) {
	node* p = getNode(), * q = NULL;
	p->elem = elem;
	if (*head == NULL) {
		*head = getNode();
		(*head)->elem = elem;
	}
	else {
		q = *head;
		while (q->next != NULL) {
			q = q->next;
		}
		q->next = p;
	}
}

int removeFirst(node** head) {
	if (*head == NULL) {
		//emptySetException();
		return -1;
	}
	node* tmp = *head;
	int elem = tmp->elem;
	(*head) = (*head)->next;
	free(tmp);
	return elem;
}

int subset(node** A, node** B) {
	if (*A == NULL) return 0;
	while (*A != NULL) {
		if (*B == NULL) return (*A)->elem;
		if ((*A)->elem == (*B)->elem) {
			removeFirst(A);
			removeFirst(B);
		}
		else if ((*A)->elem < (*B)->elem) {
			return (*A)->elem;
		}
		else if ((*A)->elem > (*B)->elem) {
			removeFirst(B);
		}
	}
	return 0;
}

void clear_set(node* head) {
	node* p = head, * tmp = NULL;
	while (p != NULL) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

int main() {
	node* A = NULL, * B = NULL;
	int n = 0, num = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		addLast(&A, num);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		addLast(&B, num);
	}
	int result = subset(&A, &B);
	printf("%d", result);
	clear_set(A);
	clear_set(B);
}
/*
3
4 6 13
6
1 3 4 6 8 13

3
7 10 53
4
7 10 15 45
*/