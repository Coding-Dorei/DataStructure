#include<stdio.h>
#include<stdlib.h>

int count_letter(char* str, char* end, int cnt, char search) {
	if (str < end) {
		if (*str == search) {
			cnt += 1;
		}
		count_letter(str + 1, end, cnt, search);
	}
	else return cnt;
}

int main() {
	
	char str[101] = { 0, };
	scanf("%s\n", str);
	char search = '\0';
	scanf("%c", &search);
	char* term = str + strlen(str);
	
	
	int result = count_letter(str, term, 0, search);
	
	
	
	printf("%d", result);
}
/*
SheIsAStudent
s
*/