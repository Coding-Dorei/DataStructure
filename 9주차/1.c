#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(char* str, char c, int* t, int size) {
	if (*t == size - 1) {
		printf("Stack FULL\n");
		return;
	}
	*t = *t + 1;
	str[*t] = c;
	return;
}
char pop(char* str, int* t) {
	if (*t == -1) {
		printf("Stack Empty\n");
		return 0;
	}
	char tmp = str[*t];
	str[*t] = 0;
	(*t)--;
	return tmp;
}
void peek(char* str, int t) {
	if (t == -1) {
		printf("Stack Empty\n");
		return;
	}
	printf("%c\n", str[t]);
	return;
}
void duplicate(char* str, int* t, int size) {
	if (*t == size - 1) {
		printf("Stack FULL\n");
		return;
	}
	char tmp = pop(str, t);
	if (tmp == 0)return;
	push(str, tmp, t, size);
	push(str, tmp, t, size);
	return;
}

void swap(char* q, char* p) {
	char tmp = *p;
	*p = *q;
	*q = tmp;
}

void upRotate(char* str, int n, int t) {
	for (int i = t; i > t - n + 1; i--) {
		swap(str + i, str + i - 1);
	}
}

void downRotate(char* str, int n, int t) {
	for (int i = t - n + 1; i < t; i++) {
		swap(str + i, str + i + 1);
	}
}

void print(char* str, int t) {
	for (int i = t; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");
}

int main() {
	int t = -1, n = 0, action = 0, size = 0;
	char mode[6] = { 0, }, c = 0;
	scanf("%d%d", &n, &action);
	char* str = (char*)calloc(n, sizeof(char));
	size = n;
	for (int i = 0; i < action; i++) {
		scanf("%s", mode);
		if (strcmp(mode, "POP") == 0) {
			pop(str, &t);
		}
		else if (strcmp(mode, "PUSH") == 0) {
			getchar();
			scanf("%c", &c);
			//printf("c:[%c]\n", c);
			push(str, c, &t, size);
		}
		else if (strcmp(mode, "PEEK") == 0) {
			peek(str, t);
		}
		else if (strcmp(mode, "DUP") == 0) {
			if(t != -1)duplicate(str, &t, size);
		}
		else if (strcmp(mode, "UpR") == 0) {
			scanf("%d", &n);
			if(n <= t+1)upRotate(str, n, t);
		}
		else if (strcmp(mode, "DownR") == 0) {
			scanf("%d", &n);
			if(n <= t+1)downRotate(str, n, t);
		}
		else if (strcmp(mode, "PRINT") == 0) {
			print(str, t);
		}
		//printf("mode : %s\n", mode);
		//printf("<main> t : %d\n", t);
	}
	free(str);
}
/*
4
10
POP
PUSH s
PUSH t
PUSH a
PUSH r
PRINT
UpR 3
PRINT
PUSH s
PEEK

3
5
PUSH d
DUP
PUSH a
PRINT
PUSH s
*/