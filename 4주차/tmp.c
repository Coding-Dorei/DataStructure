#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char elem;
	struct node* prev, * next;
}Node;

Node* getNode(char elem) {
	Node* new_node = (Node*)calloc(1, sizeof(Node));
	new_node->elem = elem;
	return  new_node;
}

void add(Node* list, int, char);
void delete(Node* list, int);
void print(Node* list);
void get(Node* list, int);


int main() {
	Node* header = NULL, * trailer = NULL;
	header = getNode('\0');
	trailer = getNode('\0');
	header->next = trailer;
	trailer->prev = header;
	add(header, 1, 'c');
	add(header, 2, 'l');
	add(header, 3, 'D');
	add(header, 3, 'a');
	add(header, 4, 'n');
	delete(header, 5);
	print(header);
	get(header, 3);
}

void print(Node* list) {
	Node* p = list;
	while (p->next != NULL) {
		p = p->next;
		printf("%c", p->elem);
	}
	printf("\n");
}

void add(Node* list, int r, char elem) {
	Node* p = list;
	for (int i = 1; i <= r; i++) {
		p = p->next;
	}
	Node * new_node = getNode(elem);
	new_node->prev = p->prev;
	new_node->next = p;
	p->prev->next = new_node;
	p->prev = new_node;
}

void delete(Node* list, int r) {
	Node* p = list, * tmp = NULL;
	for (int i = 0; i < r; i++) {
		p = p->next;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
}

void get(Node* list, int r) {
	Node* p = list;
	for (int i = 0; i < r; i++) {
		p = p->next;
	}
	printf("%c\n", p->elem);
}