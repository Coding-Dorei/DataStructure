#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	int data;
	struct node* left, * right;
}node;

node* getNode() {
	node* p = (node*)calloc(1, sizeof(node));
	return p;
}

int isInternal(node* tree) {
	if (tree->left == NULL && tree->right == NULL) return 0;
	return 1;
}

//void build_tree(node** root, int n) {
//	*root = getNode();
//	node* p = *root, * prev = NULL;
//	int x = 0, y = 0, z = 0;
//	for (int i = 0; i < n; i++) {
//		scanf("%d%d%d", &x, &y, &z);
//		if (i == 0) p->data = x;
//		else {
//			if(p->right->data == )
//		}
//		if (y != 0) {
//			p->left = getNode();
//			p->left->data = y;
//		}
//		if (z != 0) {
//			p->right = getNode();
//			p->right->data = z;
//		}
//	}
//}

void build_tree(node* v) {
	int x = 0, y = 0, z = 0;
	scanf("%d%d%d", &x, &y, &z);
	v->data = x;
	if (y != 0) {
		v->left = getNode();
		v->left->data = y;
		build_tree(v->left);
	}
	if (z != 0) {
		v->right = getNode();
		v->right->data = y;
		build_tree(v->right);
	}
	if (y == 0 && z == 0) return;
}

void preorder(node* v) {
	if (v == NULL) return;
	printf("%d ", v->data);
	if (isInternal(v)) {
		preorder(v->left);
		preorder(v->right);
	}
}

void free_tree(node* v) {
	if (v == NULL)return;
	free_tree(v->left);
	free_tree(v->right);
	free(v);
}

void search(node* root, char* str) {
	node* p = root;
	for (char* c = str; c < str + strlen(str) + 1; c++) {
		printf(" %d", p->data);
		if (*c == 'R') {
			p = p->right;
		}
		else if (*c == 'L') {
			p = p->left;
		}
	}
	printf("\n");
}

int main() {
	int n = 0, s = 0;
	char str[100] = { 0, };
	scanf("%d", &n);
	node* root = getNode();
	build_tree(root);
	scanf("%d",&s);
	for (int i = 0; i < s; i++) {
		scanf("%s", str);
		search(root, str);
	}
	free_tree(root);
}
/*
9
5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
3
RLL
LL
LR
*/