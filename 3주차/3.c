#include<stdio.h>
#include<stdlib.h>

void print(int n) {
	printf("%d\n",n%10);
	if(n>9){
		print(n/10);
	}
}

int main() {
	
	int n = 0;
	
	scanf("%d", &n);
	
	print(n);
	
	
}