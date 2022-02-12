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
		//printf("Stack Empty\n");
		return 0;
	}
	char tmp = str[*t];
	str[*t] = 0;
	(*t)--;
	return tmp;
}

void print(char* str, int t) {
	for (int i = t; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");
}

int main() {
	char* stack = NULL;
	int N = 0, t = -1;
	char str[1001] = { 0, }, tmp = 0;
	gets(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			N++;
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			N++;
		}
	}
	stack = (char*)calloc(N, sizeof(char));
	for (int i = 0; i < len; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			push(stack, str[i], &t, N);
		}
		if (str[i] == ')') {
			if (tmp = pop(stack, &t) != '(') {
				push(stack, tmp, &t, N);
			}
		}
		else if (str[i] == '}') {
			if (tmp = pop(stack, &t) != '{') {
				push(stack, tmp, &t, N);
			}
		}
		else if (str[i] == ']') {
			if (tmp = pop(stack, &t) != '[') {
				push(stack, tmp, &t, N);
			}
		}
	}
	if (t == -1)printf("OK_%d", N);
	else printf("Wrong_%d", N);
}