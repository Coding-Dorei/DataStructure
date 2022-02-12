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
	if (*t  == 100) {
		printf("fullStackException\n");
		return;
	}
	arr[++(*t)] = symbol;
}

int isOperand(char c) {
	if (c >= 'A' && c <= 'Z') return 1;
	return 0;
}

int prior_cmp(prior arr[], char op1, char op2) {
	int rank1 = 0, rank2 = 0;
	for (int i = 0; i < 9; i++) {
		if (arr[i].op == op1) {
			rank1 = arr[i].rank;
			break;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (arr[i].op == op2) {
			rank2 = arr[i].rank;
			break;
		}
	}
	return rank1 - rank2;
}

void convert(char* str, char stack[], int* t) {
	prior arr[9] = { '|', 1,'&', 2 ,'<' , 3,'>',3,'-',4,'+',4,'/',5,'*',5,'!',6 };
	char* p = str, tmp = 0;
	int unary = -100;
	while (*p != '\0') {
		if (isOperand(*p)) printf("%c", *p);
		else if (*p == '(') {
			push(stack, t, *p);
		}
		else if (*p == ')') {
			while (stack[*t] != '(') {
				tmp = pop(stack, t);
				printf("%c", tmp);
				if (tmp == '&' || tmp == '|') printf("%c", tmp);
			}
			pop(stack, t);
		}
		else {
			if ((!isOperand(*(p - 1)) && (*p == '+' || *p == '-' || *p == '!') && *(p - 1) != ')') || (str == p && (*p == '+' || *p == '-' || *p == '!'))) {
				push(stack, t, *p);
				unary = *t;
				p++;
				continue;
			}
			while (*t != -1 && prior_cmp(arr, *p, stack[*t]) <= 0) {
				tmp = pop(stack, t);
				printf("%c", tmp);
				if (tmp == '&' || tmp == '|') printf("%c", tmp);
			}
			
			push(stack, t, *p);
			if (*p == '&' || *p == '|') p++;
		}
		if (unary == *t) {
			printf("%c", pop(stack, t));
			unary = -100;
		}
		tmp = 0;
		p++;
	}
	while (*t > -1) {
		tmp = pop(stack, t);
		printf("%c", tmp);
		if (tmp == '&' || tmp == '|')printf("%c", tmp);
	}
}

int main() {
	char str[101] = { 0, };
	int t = -1;
	char* stack = NULL;
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		stack = (char*)calloc(strlen(str), sizeof(char));
		convert(str, stack, &t);
		free(stack);
		t = -1;
		printf("\n");
	}
}
/*
5
A*B+C+(D+E)*-F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
1
A&&B||C||!(E>F) ->무한루프발생
AB&&C||
1
+F*-E ->예외 발생
*/