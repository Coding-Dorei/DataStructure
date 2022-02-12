#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int hour;
	int min;
	int sec;
}TIME;

int main() {
	TIME early = { 0, }, late = { 0, }, gap = { 0, };
	scanf("%d %d %d", &early.hour, &early.min, &early.sec);
	scanf("%d %d %d", &late.hour, &late.min, &late.sec);
	gap.hour = late.hour - early.hour;
	gap.min = late.min - early.min;
	gap.sec = late.sec - early.sec;
	if (gap.sec < 0) {
		gap.sec += 60;
		gap.min -= 1;
	}
	if (gap.min < 0) {
		gap.min += 60;
		gap.hour -= 1;
	}
	printf("%d %d %d", gap.hour, gap.min, gap.sec);
}