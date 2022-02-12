#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char* p, char* q) {
	char tmp = *p;
	*p = *q;
	*q = tmp;
}

void shift(char* str, int len) {
	for (char* p = str; p < str + len - 1; p++) {
		swap(p, p + 1);
	}
	printf("%s\n", str);
}

int main() {
	char str[101] = { 0, };
	scanf("%s", str);
	printf("%s\n", str);
	for (int i = 0; i < strlen(str); i++) {
		shift(str, strlen(str));
	}
}