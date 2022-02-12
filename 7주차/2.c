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

void print(node* header) {
	node* p = header;
	if (header == NULL) printf("0\n");
	while (p != NULL) {
		printf("%d ", p->elem);
		p = p->next;
	}
}

void addLast(node* header, int elem) {
	node* p = header, * q = NULL;
	while (p->next != NULL) {
		p = p->next;
	}
	q = getNode();
	q->elem = elem;
	p->next = q;
}

node* _union(node* A, node* B) {
	if (A == NULL && B == NULL) {
		return NULL;
	}
	node* p = getNode();
	if (A == NULL) {
		p->elem = B->elem;
		p->next = _union(A, B->next);
	}
	else if (B == NULL) {
		p->elem = A->elem;
		p->next = _union(A->next, B);
	}
	else {
		if (A->elem < B->elem) {
			p->elem = A->elem;
			p->next = _union(A->next, B);
		}
		else if (A->elem > B->elem) {
			p->elem = B->elem;
			p->next = _union(A, B->next);
		}
		else {
			p->elem = B->elem;
			p->next = _union(A->next, B->next);
		}
	}
	return p;
}

node* intersect(node* A, node* B) {
	if (A == NULL || B == NULL) return NULL;
	node* p = getNode();
	if (A->elem == B->elem) {
		p->elem = A->elem;
		p->next = intersect(A->next, B->next);
		return p;
	}
	else if (A->elem > B->elem) {
		return intersect(A, B->next);
	}
	else if (A->elem < B->elem) {
		return intersect(A->next, B);
	}
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
	node* A = getNode(), * B = getNode(); // header
	int n = 0, num = 0;
	A->next = NULL;
	B->next = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		addLast(A, num);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		addLast(B, num);
	}
	node* result_union = _union(A->next, B->next), *result_intersect = intersect(A->next, B->next);
	print(result_union);
	printf("\n");
	print(result_intersect);
	clear_set(A);
	clear_set(B);
	clear_set(result_union);
	clear_set(result_intersect);
}
/*
6
3 7 45 88 99 101
4
7 10 15 45
*/