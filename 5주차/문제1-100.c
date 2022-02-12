#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char data;
	struct node* prev, * next;
}node;


void add(node*, int, char);
void del(node*, int);
char get(node*, int);
void print(node*);
void clear(node*);

node* get_Node(char data) {
	node* new_node = (node*)calloc(1, sizeof(node));
	new_node->data = data;
	return new_node;
}
int main() {
	int node_num = 0;
	node* H = (node*)calloc(1, sizeof(node)), * trailer = (node*)calloc(1, sizeof(node));
	H->next = trailer;
	trailer->prev = H;
	int n = 0, index = 0;
	char mode = '\0', data = '\0', tmp = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		mode = getchar();
		tmp = getchar();
		//printf("mode:%c\n", mode);
		if (mode == 'A') {
			scanf("%d", &index);
			getchar();
			data = getchar();
			getchar();
			//printf("index:%d data:%c\n", index, data);
			add(H, index, data);
		}
		else if (mode == 'P') {
			print(H);
			printf("\n");
		}

		else if (mode == 'D') {
			scanf("%d", &index);
			getchar();
			del(H, index);
		}
		else if (mode == 'G') {
			scanf("%d", &index);
			getchar();
			//printf("index:%d\n", index);
			tmp = get(H, index);
			if (tmp != 0) printf("%c\n", tmp);
		}
		//printf("tmp:%c\n",tmp);
	}
	clear(H);
	free(H);
	free(trailer);
}

void add(node* H, int index, char data) {
	node* p = H;
	for (int i = 1; i < index; i++) {
		p = p->next;
		if (p->next == NULL) {
			printf("invalid position\n");
			return;
		}
	}
	node* new_node = get_Node(data);
	new_node->next = p->next;
	new_node->prev = p;
	p->next->prev = new_node;
	p->next = new_node;
}

void print(node* H) {
	node* p = H;
	while (1) {
		p = p->next;
		if (p->next == NULL) break;
		printf("%c", p->data);
	}
}

void del(node* H, int index) {
	node* p = H;
	for (int i = 0; i < index; i++) {
		p = p->next;
		if (p->next == NULL) {
			printf("invalid position\n");
			return;
		}
	}
	node* prev = p->prev, * next = p->next;
	next->prev = prev;
	prev->next = next;
	free(p);
}

char get(node* H, int index) {
	node* p = H;
	for (int i = 0; i < index; i++) {
		p = p->next;
		if (p->next == NULL) {
			printf("invalid position\n");
			return 0;
		}
	}
	return p->data;
}

void clear(node* H) {
	node* p = H, * tmp = NULL;
	while (p->next != NULL) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
}
/*
5
A 1 D
A 2 a
A 3 y
D 1
P

5
A 1 S
A 2 t
A 3 r
A 3 a
G 1

7
A 1 D
A 2 a
A 3 y
D 1
P
A 1 S
P

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