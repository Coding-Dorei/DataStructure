#include<stdio.h>
#include<stdlib.h>

int sigma(int n, int sum) {
	if (n > 0) {
		sigma(n - 1, sum + n);
	}
	else if (n == 0) return sum;
	else return -1;
}


int main() {
	int n = 0;
	
	scanf("%d", &n);
	int sum = sigma(n, 0);
	
	
	
	printf("%d", sum);
}