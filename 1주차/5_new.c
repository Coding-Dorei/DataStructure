#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int hour, min, sec;
}time;

int main() {
	time before = { 0, }, after = { 0, };
	scanf("%d%d%d", &before.hour, &before.min, &before.sec);
	before.sec += before.hour * 60 * 60 + before.min * 60;
	scanf("%d%d%d", &after.hour, &after.min, &after.sec);
	after.sec += after.hour * 60 * 60 + after.min * 60;
	after.sec = after.sec - before.sec;
	after.hour = after.sec / 3600;
	after.sec %= 3600;
	after.min = after.sec / 60;
	after.sec %= 60;
	printf("%d %d %d", after.hour, after.min, after.sec);
}