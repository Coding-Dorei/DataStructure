#include<stdio.h>

int gcd(int m, int n) {
	if (m == 0 || n == 0) {
		return m + n;
	}
	else {
		if (m > n) gcd(m % n, n);
		else gcd(m, n % m);
	}
}

int main() {
	int m = 0, n = 0;
	scanf("%d%d", &m, &n);
	int result = gcd(m, n);
	printf("%d", result);
}