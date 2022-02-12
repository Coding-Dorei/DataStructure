#include<stdio.h>

int sum(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result += i;
	}
	return result;
}

int main() {
	int x = 0, result = 0;
	scanf("%d", &x);
	for (int i = 1; i <= x; i++) {
		result += sum(i);
	}
	printf("%d", result);
}