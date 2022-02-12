#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	char elem;
	struct node* next;
	struct node* prev;
}Node;

int add(Node* head, int idx, char item) {
	Node* p = head;
	for (int i = 0; i < idx; i++) {
		p = p->next;
	}
	if (p == NULL) {
		printf("invalid position");
		return -1;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->elem = item;
	tmp->prev = p->prev;
	tmp->next = p;
	p->prev->next = tmp;
	p->prev = tmp;
	return 1;
}

void print(Node* head) {
	Node* p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%c", p->elem);
	}
	printf("\n");
}

void get(Node* head, int idx) {
	Node* p = head;
	for (int i = 0; i < idx; i++) {
		p = p->next;
	}
	if (p->next == NULL) {//case: p == trailer
		printf("invalid position\n");
	}
	else printf("%c\n", p->elem);
}

void del(Node* head, int idx) {
	Node* p = head;
	for (int i = 0; i < idx; i++) {
		p = p->next;
	}
	if (p->next == NULL) {//case: p == trailer
		printf("invalid position");
		return;
	}
	else {
		Node* tmp = p->next;
		p->prev->next = tmp;
		tmp->prev = p->prev;
		free(p);
	}
}

int main() {
	Node header = { 0, }, trailer = { 0, };
	header.next = &trailer;
	trailer.prev = &header;
	int n = 0, idx = 0;
	char mode = '\0', elem = '\0';
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c",&mode);
		//printf("mode : %c\n", mode);
		getchar();
		switch (mode) {
			case('A'):
				scanf("%d %c", &idx, &elem);
				getchar();
				//printf("idx : %d, elem : %c\n", idx, elem);
				add(&header, idx, elem);
				break;
			case('P'):
				print(&header);
				break;
			case('G'):
				scanf("%d", &idx);
				getchar();
				//printf("idx : %d\n", idx);
				get(&header, idx);
				break;
			case('D'):
				scanf("%d", &idx);
				getchar();
				//printf("idx : %d\n", idx);
				del(&header, idx);
				break;
		}
	}
}
/*
ex1)
5
A 1 S
A 2 t
A 3 r
A 3 a
P

ex2)
9
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
G 3
*/