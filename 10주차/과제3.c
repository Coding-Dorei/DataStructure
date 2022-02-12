#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

int stack_size = 0;//스택의 크기를 저장할 전역변수

typedef struct node {//연결스택을 구현하기 위한 구조체
	int elem;
	int min;//find_min을 상수시간에 수행하기위한 멤버 min
	struct node* next;
}node;

node* getNode() {//노드 생성 함수
	node* p = (node*)calloc(1, sizeof(node));
	return p;
}

int pop(node** t) {
	if (*t == NULL) return -1;//빈 스택을 pop할 경우 -1을 반환하여 오류를 나타냄
	int num = (*t)->elem;//스택의 top에 있는 값을 num에 저장
	node* p = *t;
	*t = (*t)->next;//top을 다음 노드로 옮김
	free(p);//노드 삭제
	stack_size--;//스택의 크기를 1 줄임
	return num;//pop한 값을 반환
}

void push(node** t, int elem) {
	node* p = getNode();//노드를 생성함
	p->elem = elem;//생성된 노드에 정보를 저장
	if (stack_size == 0) {//빈 스택일 경우
		p->min = elem;//최솟값은 elem이 되고
		*t = p;//top은 생성된 노드
		stack_size++;//스택의 크기 +1
	}
	else {//스택이 비어있지 않을 경우
		p->next = *t;//생성된 노드가 가리키는 다음 노드를 top으로 하고
		if ((*t)->min > elem) p->min = p->elem;////이전 최솟값보다 elem이 더 작으면 최솟값을 갱신
		else p->min = (*t)->min;//아니면 이전 최솟값을 유지
		*t = p;//top을 생성된 노드로 옮김
		stack_size++;//스택의 크기를 1 증가 시킴
	}
}

void pushMilion(node** t) {
	for (int i = 0; i < 1000000; i++) {//push를 100만번 진행
		srand(time(NULL));
		push(t, rand() % 9000 + 1000);//1000 ~ 9999 범위 내에서 난수를 생성하고 이를 스택에 push
	}
}

void popMilion(node **t) {
	for (int i = 0; i < 1000000; i++) {//pop을 100만번 진행
		pop(t);
	}
}

int find_min(node* t) {
	return t->min;//스택 내에 저장된 값들의 최솟값은 top에 있는 노드의 min에 저장되어 있음
}

void free_stack(node** t) {
	while (stack_size != 0) {//스택의 크기가 0이 될때 까지
		pop(t);//pop하여 메모리를 해제함
	}
}

int main(){
	node* t = NULL;
	LARGE_INTEGER start = { 0, }, end = { 0, }, diff = { 0, }, ticks = { 0, };//실행시간 측정을 위한 변수
	QueryPerformanceFrequency(&ticks);
	char mode = 0;
	int num = 0;
	while (mode != 'q') {//종료조건인 q가 입력되기 전까지 반복
		scanf("%c", &mode);//명령을 입력받음
		getchar();//공백이 mode에 입력되지 않게 하기위해 getchar()
		if (mode == 'p') {//push
			scanf("%d", &num);
			getchar();
			QueryPerformanceCounter(&start);//시작시간과
			push(&t, num);
			QueryPerformanceCounter(&end);//종료시간의 차이를 이용하여
			printf("push %d (%d)", num, stack_size);
			diff.QuadPart = end.QuadPart - start.QuadPart;//실행시간을 측정함
			printf(", cputime = %.10lf\n", ((double)diff.QuadPart / (double)ticks.QuadPart) * 1000);//1000을 곱해서 밀리초의 형태로 나타냄
		}
		else if (mode == 'o') {
			QueryPerformanceCounter(&start);//시작시간과
			num = pop(&t);
			QueryPerformanceCounter(&end);//종료시간의 차이를 이용하여
			printf("pop %d (%d)", num, stack_size);
			diff.QuadPart = end.QuadPart - start.QuadPart;//실행시간을 측정함
			printf(", cputime = %.10lf\n", ((double)diff.QuadPart / (double)ticks.QuadPart) * 1000);//1000을 곱해서 밀리초의 형태로 나타냄
			
		}
		else if (mode == 'f') {
			QueryPerformanceCounter(&start);//시작시간과
			printf("min %d (%d)", find_min(t),stack_size);
			QueryPerformanceCounter(&end);//종료시간의 차이를 이용하여
			diff.QuadPart = end.QuadPart - start.QuadPart;//실행시간을 측정함
			printf(", cputime = %.10lf\n", ((double)diff.QuadPart / (double)ticks.QuadPart) * 1000);//1000을 곱해서 밀리초의 형태로 나타냄
		}
		else if (mode == 'P') {
			QueryPerformanceCounter(&start);//시작시간과
			pushMilion(&t);
			QueryPerformanceCounter(&end);//종료시간의 차이를 이용하여
			printf("pushMilion (%d)", stack_size);
			diff.QuadPart = end.QuadPart - start.QuadPart;//실행시간을 측정함
			printf(", cputime = %.10lf\n", ((double)diff.QuadPart / (double)ticks.QuadPart) * 1000);//1000을 곱해서 밀리초의 형태로 나타냄
			
		}
		else if (mode == 'O') {
			QueryPerformanceCounter(&start);//시작시간과
			popMilion(&t);
			QueryPerformanceCounter(&end);//종료시간의 차이를 이용하여
			printf("popMilion (%d)", stack_size);
			diff.QuadPart = end.QuadPart - start.QuadPart;//실행시간을 측정함
			printf(", cputime = %.10lf\n", ((double)diff.QuadPart / (double)ticks.QuadPart) * 1000);//1000을 곱해서 밀리초의 형태로 나타냄
		}
	}
	free_stack(&t);//메모리를 해제함
}