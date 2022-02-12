#include<stdio.h>
#include<stdlib.h>

void hanoi(int plate_num, char from, char to, char other) {
	if (plate_num > 0) {
		hanoi(plate_num - 1, from, other, to);
		printf("%c %c\n", from, to);
		hanoi(plate_num - 1, other, to, from);
	}
}

int main() {
	
	int n = 0;
	scanf("%d", &n);
	
	
	hanoi(n, 'A', 'C', 'B');
	
	
	
}