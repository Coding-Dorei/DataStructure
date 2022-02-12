#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int modulo(int a, int b) {
	while (a >= 0) {
		a -= b;
	}
	a += b;
	return a;
}

int main() {
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	int result = modulo(a, b);
	printf("%d", result);
}