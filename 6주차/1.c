#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int coef, exp;
	struct node* next;
}node;

node* getNode() {
	node* new_node = (node*)calloc(1, sizeof(node));
	return new_node;
}

void appendTerm(node* k, int c, int e) {
	node* t = getNode();
	t->coef = c;
	t->exp = e;
	t->next = NULL;
	k->next = t;
	//printf("k :%d %d\n", k->coef, k->exp);
	//printf("t :%d %d\n", t->coef, t->exp);
}

node* addPoly(node* x, node* y) {
	node* result = getNode(), * k = result;
	node* header = getNode();
	header->next = k;
	int sum = 0;
	node* i = x->next, *j = y->next;
	while (i != NULL && j != NULL) {
		if (i->exp > j->exp) {
			appendTerm(k, i->coef, i->exp);
			k = k->next;
			i = i->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(k, j->coef, j->exp);
			k = k->next;
			j = j->next;
		}
		else if(i->exp == j->exp){
			sum = i->coef + j->coef;
			if (sum != 0) {
				appendTerm(k, sum, i->exp);
				k = k->next;
			}
			i = i->next;
			j = j->next;
			sum = 0;
		}
	}
	while (i != NULL) {
		appendTerm(k, i->coef, i->exp);
		k = k->next;
		i = i->next;
	}
	while (j != NULL) {
		appendTerm(k, j->coef, j->exp);
		k = k->next;
		j = j->next;
	}
	return header->next;
}

void print(node* header) {
	node* p = header->next;
	while (p != NULL) {
		printf(" %d %d", p->coef,p->exp);
		p = p->next;
	}
	printf("\n");
}

void clear(node * header){
	node*p = header, *tmp = NULL;
	while(p->next != NULL){
		tmp = p;
		p=p->next;
		free(tmp);
	}
}

int main() {
	int m = 0, n = 0, coef = 0, exp = 0;
	node* header_x = getNode(), *header_y = getNode();
	node* x = getNode(), * y = getNode();
	header_x = x;
	header_y = y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &coef, &exp);
		//printf("coef:%d exp:%d\n", coef, exp);
		appendTerm(x, coef, exp);
		x = x->next;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &coef, &exp);
		//printf("coef:%d exp:%d\n", coef, exp);
		appendTerm(y, coef, exp);
		y = y->next;
	}
	node* result = addPoly(header_x, header_y);
	//print(header_x);
	//print(header_y);
	print(result);
	clear(result);
	clear(header_x);
	clear(header_y);
}
/*
3
5 3 3 2 3 1
3
2 6 2 3 1 0
*/