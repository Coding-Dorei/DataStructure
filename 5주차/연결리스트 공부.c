#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

Node* add_first(Node* head) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->next = head;
	scanf("%d", &tmp->data);
	return tmp;
}
void print(Node* head) {
	Node* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void insert(Node* prev, int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->next = prev->next;
	tmp->data = data;
	prev->next = tmp;
}

Node* remove_after(Node* prev) {
	Node* tmp = prev->next;
	if (tmp == NULL) return NULL;
	prev->next = tmp->next;
	return tmp;
}

Node* find(Node * head, int data) {
	Node* p = head;
	while (p != NULL) {
		if (data == p->data) return p;
		p = p->next;
	}
	return NULL;
}

int main() {
	Node* head = NULL;
	head = add_first(head);
	insert(head, 5);
	Node * tmp = find(head, 5);
	insert(tmp, 7);
	print(head);
}