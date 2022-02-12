#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct priority {
	char op;
	int rank;
}prior;

char pop(char arr[], int* t) {
	if (*t == -1) {
		printf("emptyStackException\n");
		return -1;
	}
	char tmp = arr[*t];
	arr[*t] = 0;
	*t = *t - 1;
	return tmp;
}

void push(char arr[], int* t, char symbol) {
	if (*t == 100) {
		printf("fullStackException\n");
		return;
	}
	arr[++(*t)] = symbol;
}

int isOperand(char c) {
	if (c >= '0' && c <= '9') return 1;
	return 0;
}

int evaluate(char* str, char *stack, int *t) {
	int result = 0, num1 = 0, num2 = 0;
	char* p = str;
	while (*p != '\0') {
		if (!isOperand(*p)) {
			num1 = pop(stack, t) - '0';
			num2 = pop(stack, t) - '0';
			if (*p == '+') {
				result = num2 + num1;
				push(stack, t, result + '0');
			}
			else if (*p == '-') {
				result = num2 - num1;
				push(stack, t, result + '0');
			}
			else if (*p == '*') {
				result = num2 * num1;
				push(stack, t, result + '0');
			}
			else if (*p == '/') {
				result = num2 / num1;
				push(stack, t, result + '0');
			}
		}
		else {
			push(stack, t, *p);
		}
		p++;
	}
	result = pop(stack, t) - '0';
	return result;
}

int main() {
	char str[101] = { 0, };
	int t = -1;
	char* stack = NULL;
	int n = 0, result = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		stack = (char*)calloc(strlen(str), sizeof(char));
		result = evaluate(str, stack, &t);
		printf("%d\n", result);
		free(stack);
	}
}
/*
4
53*2+63+2*+
234*+
72/3-42*+21*-
923*1+2*+
*/